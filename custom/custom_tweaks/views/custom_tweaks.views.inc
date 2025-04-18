<?php

/**
 * Implements hook_views_data_alter().
 */
function custom_tweaks_views_data_alter(&$data) {
  $data['node']['helios_documents_filter'] = array(
    'group' => 'Content',
    'title' => t('Helios: Documents filter'),
    'title short' => t('Helios: Documents filter'),
    'help' => t('Document filters based on complex rules.'),
    //'real field' => 'field_type',
    'filter' => array(
      'handler' => 'custom_tweaks_handler_filter_documents_types',
    ),
  );

  $data['node']['helios_visuals_title'] = array(
    'title' => t('Dynamic title for the visuals table.'),
    'help' => t('Dynamic title for the visuals table.'),
    'field' => array(
      'handler' => 'custom_tweaks_handler_field_visuals_title',
      'click sortable' => TRUE,
    ),
  );

  $data['node']['helios_visuals_second_title'] = array(
    'title' => t('Dynamic second title for the visuals table.'),
    'help' => t('Dynamic second title for the visuals table.'),
    'field' => array(
      'handler' => 'custom_tweaks_handler_field_visuals_second_title',
      'click sortable' => TRUE,
    ),
  );

  $data['node']['helios_visuals_format'] = array(
    'title' => t('Dynamic format field.'),
    'help' => t('Dynamic format field for the visuals table.'),
    'field' => array(
      'handler' => 'custom_tweaks_handler_field_visuals_format',
      'click sortable' => TRUE,
    ),
  );
}
