<?php

/**
 * Entity class representing the commerce_cardonfile entity type.
 */
class CommerceCardOnFile extends Entity {

  /**
   * The card id.
   *
   * @var integer
   */
  public $card_id;

  /**
   * The uid of the card owner.
   *
   * @var integer
   */
  public $uid;

  /**
   * The method_id of the payment method that stored the card.
   *
   * @var string
   */
  public $payment_method;

  /**
   * The instance_id of the payment method that stored the card.
   *
   * @var string
   */
  public $instance_id;

  /**
   * The id of the card at the payment gateway.
   *
   * @var string
   */
  public $remote_id;

  /**
   * The card type.
   *
   * @var string
   */
  public $card_type;

  /**
   * The name on the card.
   *
   * @var string
   */
  public $card_name;

  /**
   * Truncated card number (last 4 digits).
   *
   * @var string
   */
  public $card_number;

  /**
   * Expiration month.
   *
   * @var integer
   */
  public $card_exp_month;

  /**
   * Expiration year.
   *
   * @var integer
   */
  public $card_exp_year;

  /**
   * Whether this is the default card for this payment method instance..
   *
   * @var boolean
   */
  public $instance_default = 1;

  /**
   * Card status: inactive (0), active (1), not deletable (2), declined (3).
   *
   * @var integer
   */
  public $status = 1;

  /**
   * The Unix timestamp when the card was first stored.
   *
   * @var integer
   */
  public $created;

  /**
   * The Unix timestamp when the card was last updated.
   *
   * @var integer
   */
  public $changed;

  public function __construct($values = array()) {
    parent::__construct($values, 'commerce_cardonfile');
  }

  /**
   * Overrides Entity::save().
   */
  public function save() {
    $this->changed = REQUEST_TIME;
    // Set the created timestamp during initial save.
    if (!$this->card_id) {
      $this->created = REQUEST_TIME;
    }
    // Reactivate a declined card after its expiration date has been modified.
    if ($this->card_id && $this->status == 3) {
      $this->original = entity_load_unchanged('commerce_cardonfile', $this->card_id);
      $exp_month_changed = $this->original->card_exp_month != $this->card_exp_month;
      $exp_year_changed = $this->original->card_exp_year != $this->card_exp_year;
      if ($exp_month_changed || $exp_year_changed) {
        $this->status = 1;
      }
    }

    parent::save();
  }
}