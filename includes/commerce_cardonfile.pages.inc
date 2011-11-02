<?php

/**
 * @file
 * User page callbacks and forms for Commerce Card on File.
 */


/**
 * Displays the card data overview for the "Stored payment methods" account tab.
 */
function commerce_cardonfile_overview($account) {
  // Load the specified account's stored card data.
  $stored_cards = commerce_cardonfile_data_load_multiple($account->uid);

  $header = array(
    t('Payment method'),
    t('Operations'),
  );

  // Build a table rows array of stored card data.
  $rows = array();

  foreach ($stored_cards as $card_id => $card_data) {
    // Build the operation links for the current card.
    $links = menu_contextual_links('commerce-card-data', 'user/' . $account->uid . '/stored-payment-methods', array($card_id));

    // Add the card's row to the table's rows array.
    $rows[] = array(
      theme('card_data_overview', array('card_data' => $card_data)),
      theme('links', array('links' => $links, 'attributes' => array('class' => 'commerce-card-data links inline operations'))),
    );
  }

  // Add an empty message in case the tab got rendered without stored cards.
  if (empty($rows)) {
    $rows[] = array(array('data' => t('You do not have any stored payment methods.'), 'colspan' => 2));
  }

  return theme('table', array('header' => $header, 'rows' => $rows));
}

/**
 * Builds the form for editing cardonfile data.
 *
 * @param $card_data
 *   The data array representing a card on file.
 */
function commerce_cardonfile_edit_form($form, &$form_state) {

}

/**
 * Builds the form for deleting cardonfile data.
 *
 * @param $card_data
 *   The data array representing a card on file.
 */
function commerce_cardonfile_delete_form($form, &$form_state, $card_data) {
  $form['card_data'] = array(
    '#type' => 'value',
    '#value' => $card_data,
  );

  return confirm_form(
    $form,
    t('Are you sure you want to delete this card data?'),
    'user/' . $card_data['uid'] . '/stored-payment-methods',
    theme('card_data_overview', array('card_data' => $card_data)),
    t('Delete')
  );
}

/**
 * Form submit handler: delete stored card data.
 */
function commerce_cardonfile_delete_form_submit($form, &$form_state) {
  $card_data = $form_state['values']['card_data'];

  // Invoke the payment method's card delete callback.
  $payment_method = commerce_payment_method_instance_load($card_data['instance_id']);
  $callback = $payment_method['cardonfile']['delete callback'];

  if (function_exists($callback)) {
    if (!$callback($payment_method, $card_data)) {
      // Display a message if we failed to communicate properly with the payment
      // gateway in the Card on File delete callback.
      drupal_set_message(t('We encountered an error attempting to delete your card data. Please try again and contact us if this error persists.'), 'error');
      $form_state['redirect'] = 'user/' . $card_data['uid'] . '/stored-payment-methods';
      return;
    }
  }

  // Disable the card data but retain the record.
  $card_data['status'] = 0;
  commerce_cardonfile_data_save($card_data);

  drupal_set_message(t('The stored card data has been deleted.'));

  // Redirect to the payment methods tab if the user has other stored payment.
  $stored_cards = commerce_cardonfile_data_load_multiple($card_data['uid']);

  if (!empty($stored_cards)) {
    $form_state['redirect'] = 'user/' . $card_data['uid'] . '/stored-payment-methods';
  }
  else {
    $form_state['redirect'] = 'user/' . $card_data['uid'];
  }
}
