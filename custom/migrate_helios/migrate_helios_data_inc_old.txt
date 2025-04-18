<?php

class HeliosMigration extends Migration {

  private $type;

  public function __construct($arguments) {
    parent::__construct($arguments);
    $migration = $this->machineName;

    if (!isset($arguments['type'])) {
      drupal_set_message("Error: Type of imported content for '$migration' migration is not set.", 'error');
    }

    $this->type = $arguments['type'];
    $type = $this->type;

    if (!isset($arguments['source'])) {
      drupal_set_message("Error: Source file for '$migration' migration is not set.", 'error');
    }

    $source = $arguments['source'];

    //return FALSE;

    // Human-friendly description of your migration process. Be as detailed as you like.
    $this->description = t('Migrate data from a CSV source (values enclosed in ["], ["] in values escaped by ["], values separated by [;]).');

    // Let's use a CSV file as a source
    $filename = "sites/all/migration_sources/$source";
    #$filename = 'sites/all/migration_sources/kairos_all_types_3_TEST.txt';
    $this->description = t('Import from: ' . $filename);
    $this->source = new MigrateSourceCSV(DRUPAL_ROOT . '/' . $filename, array(), array(
      'header_rows' => 1,
      'delimiter' => ';',
      'escape' => '"',
    ));

    // Define the target content type
    $this->destination = new MigrateDestinationNode('data');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'alias' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'Unique source id',
        )
      ),
      /*
      array(
        'docid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Unique source id',
          'alias' => 'nid',
        )
      ),
      */
      MigrateDestinationNode::getKeySchema()
    );

    $this->addFieldMapping('uid')
      ->defaultValue(1); // Set creator to superadmin.

    $this->addFieldMapping('language')
      ->defaultValue('en'); // Setting 'en' as default language.

    // Fields created and changed will be set at import time in prepareRow()
    //$this->addFieldMapping('created', '?');
    //$this->addFieldMapping('changed', '?');

    // Normally title is generated using automatic nodetitles BUT I am switching OFF automatic nodetitles until after all is imported!
    $this->addFieldMapping('title', 'title1');
    //->callbacks(array($this, 'get_main_name'));

    // Node alias
    $this->addFieldMapping('path', 'alias');

    // Pathauto - perform aliasing (set to 0 to prevent alias generation during migration
    $this->addFieldMapping('pathauto', '1');
    $this->addFieldMapping('field_alias', 'alias');
    $this->addFieldMapping('field_type', 'type');
    $this->addFieldMapping('field_wcode', 'wcode');
    $this->addFieldMapping('field_partno', 'partno');
    $this->addFieldMapping('field_themes', 'themes');
    $this->addFieldMapping('field_title2', 'title2');
    $this->addFieldMapping('field_keywords', 'keywords');
    $this->addFieldMapping('field_description', 'description');
    $this->addFieldMapping('field_author', 'author');
    $this->addFieldMapping('field_year', 'year');
    $this->addFieldMapping('field_month', 'month');
    $this->addFieldMapping('field_day', 'day');
    $this->addFieldMapping('field_completion', 'completion');
    $this->addFieldMapping('field_anchor', 'anchor');
    $this->addFieldMapping('field_warnings', 'warnings');
    $this->addFieldMapping('field_charset', 'charset');
    $this->addFieldMapping('field_cittok', 'cittok');
    $this->addFieldMapping('field_citfrk', 'citfrk');
    $this->addFieldMapping('field_xcode', 'xcode');
    $this->addFieldMapping('field_ycode', 'ycode');
    $this->addFieldMapping('field_zcode', 'zcode');

    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:format')
      ->defaultValue('full_html'); // Set text format.

    $this->addUnmigratedSources(array('migration'));
    $this->setHighwaterField(array(
      'name' => 'migration',
      'type' => 'int',
    ));
    /*
    $this->addFieldMapping('field_description_concept', 'FM_24');
    //->callbacks(array($this, 'get_main_subvalue')); // This is in case this field contains another [[]], e.g. [[Description]] may contain [[Counter-claim]] as in http://www.uia.be/sites/uia.be/db/db/x.php?dbcode=st&go=e&id=12902980 -- then we only need to take into account the first field! The fake field will be dealt with in prepareRow() which happens before running callbacks like this one!
    $this->addFieldMapping('field_description_concept:format')
      ->defaultValue('filtered_html'); // Set text format.

    $this->addFieldMapping('field_broader_concept', 'FM_30')
      //->separator(',');
      ->sourceMigration(array('Helios')); // Necessary for a reference field!

    // Main type
    $this->addFieldMapping('field_type_concept', 'FM_3');
    //  ->arguments(array('create_term' => TRUE));
    $this->addFieldMapping('field_type_concept:create_term')
      ->defaultValue(TRUE);
    */

    // Unmapped destination fields.
    $this->addUnmigratedDestinations(array(
      'is_new',
      'status',
      'promote',
      'revision',
      'sticky',
      'revision_uid',
      'log',
      'tnid',
      'comment',
      'translate'
    ));

    // Unmigrated source columns
    $sourcecolumns = array(
      //'FM_1',
      //'FM_2',
    );
    foreach ($sourcecolumns as $col) {
      $this->addFieldMapping(NULL, $col)->issueGroup(t('DNM'));
    }

  }

  // See https://www.drupal.org/node/1013506
  public function prepare($node, $rec) {
    //dpm($node);
    //dpm($rec);
  }

  // Callbacks.
  // Note that the callbacks are applied to the source $row field after prepareRow() is called!
  // See also http://drupal.org/node/1406802#comment-7378538
  public function prepareRow($current_row) {



    // Tidy up source values if and as needed.
    $allsourcecolumns = array(
      "type",
      "alias",
      "wcode",
      "partno",
      "themes",
      "title1",
      "title2",
      "keywords",
      "description",
      "author",
      "year",
      "month",
      "day",
      "completion",
      "anchor",
      "warnings",
      "charset",
      "cittok",
      "citfrk",
      "xcode",
      "ycode",
      "zcode",
      "body",
    );

    $sourcecolumns = $allsourcecolumns;
    foreach ($sourcecolumns as $col) {
      $current_row->$col = trim($current_row->$col);
    }

    if ($current_row->type !== $this->type) {
      return FALSE;
    }

    // For now, maybe later we can set the real dates here.
    $current_row->created = REQUEST_TIME;
    $current_row->changed = REQUEST_TIME;

    //dpm($current_row);

    return TRUE;
  }

}
