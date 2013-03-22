<?php

/**
 * @file
 * Provides metadata for the commerce cardonfile entity.
 */

/**
 * Implements hook_entity_property_info().
 */
function commerce_cardonfile_entity_property_info() {
  $info = array();

  // Add meta-data about the basic commerce_product properties.
  $properties = &$info['commerce_cardonfile_data']['properties'];

  $properties['payment_method'] = array(
    'label' => t('Payment Method'),
    'description' => t('The payment method associated with this saved payment.'),
    'type' => 'text',
    'schema field' => 'payment_method',
  );

  return $info;
}
