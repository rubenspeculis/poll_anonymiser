<?php
/**
 * @file
 * anonymous_user_feeds_importer.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function anonymous_user_feeds_importer_default_rules_configuration() {
  $items = array();
  $items['rules_anonymous_user_feed_import'] = entity_import('rules_config', '{ "rules_anonymous_user_feed_import" : {
      "LABEL" : "Anonymous User Feed Import",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "php", "rules", "feeds" ],
      "ON" : [ "feeds_import_anoymous_user_importer" ],
      "DO" : [
        { "variable_add" : {
            "USING" : {
              "type" : "text",
              "value" : "\\u003C?php \\r\\n$title = $node-\\u003Etitle;\\r\\n$token = hash(\\u0027sha256\\u0027, $title);\\r\\necho $token; ?\\u003E\\r\\n\\r\\n\\r\\n"
            },
            "PROVIDE" : { "variable_added" : { "token" : "Token" } }
          }
        },
        { "data_set" : {
            "data" : [ "node:field-poll-anonymiser-token:value" ],
            "value" : "[token:value]"
          }
        }
      ]
    }
  }');
  return $items;
}
