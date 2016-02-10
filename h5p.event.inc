<?php
require_once(drupal_get_path('module', 'h5p') . '/library/h5p-event-base.class.php');

/**
 * Makes it easy to track events throughout the H5P system.
 *
 * @package    H5P
 * @copyright  2016 Joubel AS
 * @license    MIT
 */
class H5PEvent extends H5PEventBase {

  /**
   * Store the event.
   */
  protected function save() {
    global $user;

    // Get data in array format without NULL values
    $data = $this->toArray()[0];

    // Get data in array format
    list($data) = $this->toArray();

    // Add user
    $data['user_id'] = $user->uid;

    // Insert into DB
    $this->id = db_insert('h5p_events')
      ->fields($data)
      ->execute();

    return $this->id;
  }

  /**
   * Count number of events.
   */
  protected function count() {
    $type = $this->type . ' ' . $this->sub_type;

    $current_num = db_query(
        "SELECT num
           FROM {h5p_counters}
          WHERE type = :type
            AND library_name = :library_name
            AND library_version = :library_version
        ", array(
          ':type' => $type,
          ':library_name' => $this->library_name,
          ':library_version' => $this->library_version
        ))->fetchField();

    if ($current_num === FALSE) {
      // Insert
      db_insert('h5p_counters')
          ->fields(array(
            'type' => $type,
            'library_name' => $this->library_name,
            'library_version' => $this->library_version,
            'num' => 1
          ))
          ->execute();
    }
    else {
     // Update num+1
     db_query(
         "UPDATE {h5p_counters}
             SET num = num + 1
           WHERE type = :type
             AND library_name = :library_name
             AND library_version = :library_version
         ", array(
           ':type' => $type,
           ':library_name' => $this->library_name,
           ':library_version' => $this->library_version
         ));
    }
  }
}
