<?php

/**
 * @file
 * The controller for the payment transaction entity containing the CRUD operations.
 */

/**
 * The controller class for payment transactions contains methods for the
 * transaction CRUD operations. The load method is inherited from the default
 * controller.
 */
class CommerceCardOnFileDataEntityController extends DrupalCommerceEntityController {

  /**
   * Create a default payment transaction.
   *
   * @param array $values
   *   An array of values to set, keyed by property name.
   *
   * @return object
   *   A payment transaction object with all default fields initialized.
   */
  public function create(array $values = array()) {
    global $user;

    $values += array(
      'card_id' => NULL,
      'uid' => $user->uid,
      'payment_method' => '',
      'instance_id' => '',
      'remote_id' => '',
      'card_type' => '',
      'card_name' => '',
      'card_number' => '',
      'card_exp_month' => '',
      'card_exp_year' => '',
      'status' => 1,
      'created' => REQUEST_TIME,
    );

    return parent::create($values);
  }

}
