<?php
require_once(drupal_get_path('module', 'h5p') . '/library/h5p-event-base.class.php');

/**
 * Makes it easy to track events throughout the H5P system.
 *
 * @package    H5P
 * @copyright  2016 Joubel AS
 * @license    MIT
 */
class H5P_Event extends H5PEventBase {

  /**
   * Store the event.
   */
  protected function save() {
    global $user;

    // Get data in array format without NULL values
    $data = $this->toArray()[0];

    // Insert into DB
    $this->id = db_insert('h5p_events')
      ->fields(array(
        'user_id' => $user->uid,
        'created_at' => $data['created_at'],
        'type' => $data['type'],
        'sub_type' => $data['sub_type'],
        'content_id' => $data['content_id'],
        'content_title' => $data['content_title'],
        'library_name' => $data['library_name'],
        'library_version' => $data['library_version']
      ))
      ->execute();

    return $this->id;
  }
}
