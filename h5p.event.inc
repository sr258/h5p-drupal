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
}
