<?php

/**
 * @file
 * Because the name of this file is the module name plus '.migrate.inc', when
 * hook_migrate_api is invoked by the Migrate module this file is automatically
 * loaded - thus, you don't need to implement your hook in the .module file.
 */

/*
 * You must implement hook_migrate_api(), setting the API level to 2, if you are
 * implementing any migration classes. If your migration application is static -
 * that is, you know at implementation time exactly what migrations must be
 * instantiated - then you should register your migrations here. If your
 * application is more dynamic (for example, if selections in the UI determine
 * exactly what migrations need to be instantiated), then you would register
 * your migrations using registerMigration() - see migrate_example_baseball for
 * more information.
 */
function migrate_helios_migrate_api() {


  $field_name = 'field_type';
  $field_info = field_info_field($field_name);
  $types = array_keys($field_info['settings']['allowed_values']);

  $group = 'Helios';

  $migrations = array();
  foreach ($types as $type) {
    $migrations[$type] = array(
     'class_name' => 'HeliosMigration',
     'group_name' => $group,
     'type' => $type,
     'source' => "${type}.txt",
    );
  }


  $types = array();
  foreach ($migrations as $migration) {
    $types[] = $migration['type'];
  }

  $groups = array(
    $group => array(
      'title' => t('Helios (@types)', array('@types' => implode(', ', $types))),
    ),
  );


  $api = array(

    // Required - tells the Migrate module that you are implementing version 2
    // of the Migrate API.
    'api' => 2,

    // Migrations can be organized into groups. The key used here will be the
    // machine name of the group, which can be used in Drush:
    //  drush migrate-import --group=wine
    // The title is a required argument which is displayed for the group in the
    // UI. You may also have additional arguments for any other data which is
    // common to all migrations in the group.
    'groups' => $groups,

    // Here we register the individual migrations. The keys (BeerTerm, BeerUser,
    // etc.) are the machine names of the migrations, and the class_name
    // argument is required. The group_name is optional (defaulting to 'default')
    // but specifying it is a best practice.
    'migrations' => $migrations,

  );
  return $api;
}
