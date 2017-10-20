<?php

function h5p_rules_event_info() {
  $defaults = array(
    'group' => t('H5P'),
    'module' => 'h5p',
    'access callback' => 'rules_h5p_integration_access'
  );
  return array(
    'h5p_solved' => $defaults + array(
      'label' => t('When interactive content is solved'),
      'variables' => array(
        'id' => array('type' => 'integer', 'label' => t('interactive content id')),
        'score' => array('type' => 'integer', 'label' => t('awarded score')),
        'maxScore' => array('type' => 'integer', 'label' => t('maximum score possible')),
      ),
    )
  );
}


/**
 * H5P integration access callback.
 */
function rules_h5p_integration_access($type, $name) {
  if ($type == 'event' || $type == 'condition') {
    return entity_access('view', 'h5p');
  }
}

?>