
Batch background
================

Batch background is a new approach for exectuing batchs in Drupal 7(and above). Batch helps us run a massive operation, such as sending emails, in small part. There are two approach for that:

1. Batch API - Running operation with a cool progress bar which displayed the progress of the execution status.
2. Queue worker - Running the operations via cron.

The problem is that those batches are suiteable for sending mail: Using batch API will stop the user from keep serfing the site. On the other hand using the queu worker won't send all the email instantly.

Batch background fill the gap: After setting the operations function, Drupal will exectue with JS the operations. In that case all the emails will send as long as we have users logged in to the site.

In case Batch background did not complete, the normal queue worker will complete the batch operations. 
