<?php

class BatchBackground extends Entity {

  /**
   * @var Int
   *   Primary Key: Unique batch ID.
   */
  public $bid;

  /**
   * @var Int
   *   A Unix timestamp indicating when this batch was submitted for processing.
   *   Stale batches are purged at cron time.
   */
  public $timestamp;

  /**
   * @var String
   *   A serialized array containing the processing data for the batch.
   */
  public $batch;

  /**
   * @var Int
   *   The last delta of the batch processing.
   */
  public $delta = 0;

  /**
   * Adding batch callbacks nicely.
   */
  public function AddCallback($callback, $arguments = array()) {
    $this->batch[] = array($callback, $arguments);
    return $this;
  }

  /**
   * Overrides parent::save().
   */
  public function save() {
    if ($this->delta >= count($this->batch)) {
      // We are in the last batch operation so we need to delete the current
      // instance.
      $this->delete();
      return;
    }

    parent::save();
  }
}
