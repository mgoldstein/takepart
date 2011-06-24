<?php


function takepart_newsletter_signup_bulk_feature_mail($key, &$message, $params) {
  if ($key == "report_mail") {
    $node = $params['node'];

    $message['subject'] = t("Report Ready for Email Load ") . $node->title;
    $message['body'] = theme('takepart_newsletter_signup_bulk_feature_report_mail', $node);
  }
}
