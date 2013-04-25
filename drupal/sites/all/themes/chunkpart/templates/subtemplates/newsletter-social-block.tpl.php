<? 

// The body, form and terms of service are all replaced with the response
// message.
$content .= "<div id=\"{$variables['response_id']}\">";
$content .= "<p class=\"message\">" . $variables['body'] . "</p>";
$content .= drupal_render($variables['form']);
$content .= "<p class=\"terms-of-service\">" . drupal_render($variables['tos_link']) . "</p>";
$content .= "</div>";

// Add the social service links.
$social_links = $variables['social_links'];
$content .= "<h3>" . t('Follow Us') . "</h3>";
$content .= "<ul>";

foreach ($social_links as $link) {
	$content .= "<li>" . drupal_render($link) . "</li>";
}
$content .= "</ul>";

echo $content;

?>hooba