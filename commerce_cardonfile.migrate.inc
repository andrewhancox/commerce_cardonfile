<?php

/**
 * @file
 * Support for processing Commerce Card on File in Migrate.
 */

/**
 * Destination class implementing migration into commerce card on file.
 */
class MigrateDestinationCommerceCardOnFile extends MigrateDestination {

  public function __construct() {
    parent::__construct();
  }

  static public function getKeySchema() {
    return array(
      'remote_id' => array(
        'type'        => 'varchar',
        'length'      => 255,
        'not null'    => true,
        'default'     => '',
        'description' => 'Primary Key: Unique key for menu. This is used as a block delta so length is 32.',
      ),
    );
  }

  /**
   * Returns a list of fields available to be mapped.
   *
   * @return array
   *   Keys: machine names of the fields (to be passed to addFieldMapping)
   *   Values: Human-friendly descriptions of the fields.
   */
  public function fields() {
    $fields                     = array();
    $fields['uid']              = t('User ID');
    $fields['payment_method']   = t('customer_email');
    $fields['instance_id']      = t('card_id');
    $fields['remote_id']        = t('remote_id');
    $fields['card_type']        = t('card_type');
    $fields['card_name']        = t('card_name');
    $fields['card_number']      = t('card_number');
    $fields['card_exp_month']   = t('card_exp_month');
    $fields['card_exp_year']    = t('card_exp_year');
    $fields['status']           = t('card_exp_year');
    $fields['instance_default'] = t('instance_default');

    return $fields;
  }

  /**
   * Import a single card on file type.
   *
   * @param stdClass $cardonfile
   *   Generic object, refilled with any fields mapped in the Migration.
   * @param stdClass $row
   *   Raw source data object - passed through to prepare/complete handlers.
   *
   * @return array|bool
   *   Array of product type machine names if successful. FALSE on failure.
   *
   * @throws MigrateException
   */
  public function import(stdClass $cardonfile, stdClass $row) {
    // Invoke migration prepare handlers
    $this->prepare($cardonfile, $row);

    $remote_id = (string)$cardonfile->customer_id . '|' . (string)$cardonfile->card_id;

    // Check to see if this is a new record.
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'commerce_cardonfile', '=')->propertyCondition('remote_id', $remote_id, '=');
    $entities = $query->execute();

    $update = isset($entities['commerce_cardonfile']);

    $user = user_load($cardonfile->uid);

    if ($user == false) {
      throw new MigrateException("Unable to resolve user");
    }

    $payment_method = commerce_payment_method_instance_load($cardonfile->payment_method);

    if ($payment_method == false) {
      throw new MigrateException("Unable to resolve payment method");
    }

    if ($update) {
      $entity = reset($entities['commerce_cardonfile']);
      commerce_cardonfile_delete($entity->card_id);
    }

    // Populate and save the card
    $card_data                   = commerce_cardonfile_new();
    $card_data->uid              = $cardonfile->uid;
    $card_data->payment_method   = $payment_method['method_id'];
    $card_data->instance_id      = $payment_method['instance_id'];
    $card_data->remote_id        = $cardonfile->remote_id;
    $card_data->card_type        = $cardonfile->card_type;
    $card_data->card_name        = $cardonfile->card_name;
    $card_data->card_number      = $cardonfile->card_number;
    $card_data->card_exp_month   = $cardonfile->card_exp_month;
    $card_data->card_exp_year    = $cardonfile->card_exp_year;
    $card_data->status           = $cardonfile->status;
    $card_data->instance_default = $cardonfile->instance_default;

    $this->savecard($card_data, $cardonfile);

    if (!$update) {
      $this->numCreated++;
    } else {
      $this->numUpdated++;
    }

    $this->complete($cardonfile, $row);

    return array($remote_id);
  }

  // Seperate method to allow inheritance by payment plugins.
  public function savecard($card_data) {
    commerce_cardonfile_save($card_data);
  }

  /**
   * Implementation of MigrateDestination::prepare().
   */
  public function prepare($cardonfile, stdClass $row) {
    // We do nothing here but allow child classes to act.
    $migration = Migration::currentMigration();
    $cardonfile->migrate = array(
      'machineName' => $migration->getMachineName(),
    );

    // Call any general handlers.
    migrate_handler_invoke_all('commerce_cardonfile', 'prepare', $cardonfile, $row);
    // Then call any prepare handler for this specific Migration.
    if (method_exists($migration, 'prepare')) {
      $migration->prepare($cardonfile, $row);
    }
  }

  /**
   * Implementation of MigrateDestination::complete().
   */
  public function complete($cardonfile, stdClass $row) {
    // We do nothing here but allow child classes to act.
    $migration = Migration::currentMigration();
    $cardonfile->migrate = array(
      'machineName' => $migration->getMachineName(),
    );
    // Call any general handlers.
    migrate_handler_invoke_all('commerce_cardonfile', 'complete', $cardonfile, $row);
    // Then call any complete handler for this specific Migration.
    if (method_exists($migration, 'complete')) {
      $migration->complete($cardonfile, $row);
    }
  }

  public function rollback(array $id) {
    $remote_id = reset($id);

    $this->prepareRollback($remote_id);

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'commerce_cardonfile', '=')->propertyCondition('remote_id', $remote_id, '=');
    $entities = $query->execute();

    if (isset($entities['commerce_cardonfile'])) {
      $entity = reset($entities['commerce_cardonfile']);
      commerce_cardonfile_delete($entity->card_id);
    }

    $this->completeRollback($remote_id);
  }

  /**
   * Give handlers a shot at cleaning up before a block has been rolled back.
   *
   * @param $bid
   *  ID of the custom block about to be deleted.
   */
  public function prepareRollback($cardid) {
    // We do nothing here but allow child classes to act.
    $migration = Migration::currentMigration();
    // Call any general handlers.
    migrate_handler_invoke_all('commerce_cardonfile', 'prepareRollback', $cardid);
    // Then call any complete handler for this specific Migration.
    if (method_exists($migration, 'prepareRollback')) {
      $migration->prepareRollback($cardid);
    }
  }

  /**
   * Give handlers a shot at cleaning up after a block has been rolled back.
   *
   * @param $bid
   *  ID of the custom block which has been deleted.
   */
  public function completeRollback($cardid) {
    // We do nothing here but allow child classes to act.
    $migration = Migration::currentMigration();
    // Call any general handlers.
    migrate_handler_invoke_all('commerce_cardonfile', 'completeRollback', $cardid);
    // Then call any complete handler for this specific Migration.
    if (method_exists($migration, 'completeRollback')) {
      $migration->completeRollback($cardid);
    }
  }

  /**
   * Implementation of __toString().
   *
   * @return string
   *  Description of the destination being migrated into
   */
  public function __toString() {
    return 'Creates commerce cards on file types';
  }
}
