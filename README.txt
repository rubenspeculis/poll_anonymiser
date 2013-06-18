This module was developed for MDBA to allow users to submit single submissions on a webform from behind the same IP address.

This module creates a content type, anonymous_user that links an email address to a sha256 token.
This module includes the feeds importer to import all email addresses from a csv file while automatically generating the tokens.
This module declares a webform validator that ensures that a textfield's content is found in the anonumous_user content type. If it is the field validates.
This module allows for direct mailing out to all email addresses in the content type above linking to a webform and providing that person with their unique token.

By utilising the "unique" varriable from webform alongside this module we can ensure that anonynmised data is collected whilst ensuring integrity of the voting process.

Built on 2013-06-18
Rubens Peculis
