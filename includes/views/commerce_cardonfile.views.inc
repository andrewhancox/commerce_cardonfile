<?php

/**
 * @file
 * Views integration for Commerce Card on File.
 */

/**
 * Implements hook_views_data_alter().
 */
function commerce_cardonfile_views_data_alter(&$data) {
  $data['commerce_cardonfile']['instance_default']['filter']['label'] = t('Default');
  $data['commerce_cardonfile']['instance_default']['filter']['type'] = 'yes-no';

  // Expose links to operate on the order.
  $data['commerce_cardonfile']['view_card'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a simple link to the administrator view of the card.'),
      'handler' => 'commerce_cardonfile_handler_field_card_link',
    ),
  );
  $data['commerce_cardonfile']['edit_card'] = array(
    'field' => array(
      'title' => t('Edit link'),
      'help' => t('Provide a simple link to edit the card.'),
      'handler' => 'commerce_cardonfile_handler_field_card_link_edit',
    ),
  );
  $data['commerce_cardonfile']['delete_card'] = array(
    'field' => array(
      'title' => t('Delete link'),
      'help' => t('Provide a simple link to delete the card.'),
      'handler' => 'commerce_cardonfile_handler_field_card_link_delete',
    ),
  );
  // Operation links.
  $data['commerce_cardonfile']['operations'] = array(
    'field' => array(
      'title' => t('Operations links'),
      'help' => t('Display all the available operations links for the cards.'),
      'handler' => 'commerce_cardonfile_handler_field_card_operations',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_plugins().
 */
function commerce_cardonfile_views_plugins() {
  return array(
    'argument validator' => array(
      'commerce_cof_card_id' => array(
        'title' => t('Card ID access'),
        'handler' => 'commerce_cardonfile_plugin_argument_validate_card_id',
      ),
      'commerce_cof_owner' => array(
        'title' => t('Card owner access'),
        'handler' => 'commerce_cardonfile_plugin_argument_validate_owner',
      ),
    ),
  );
}
