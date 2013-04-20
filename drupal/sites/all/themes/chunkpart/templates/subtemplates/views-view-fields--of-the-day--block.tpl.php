<?
unset($variables['view']);
unset($variables['fields']);
//_l($variables);
foreach ( $fields as $key => $field ) {
	print $key . ": ";
	print $field->content;
	print "<br/>";
}
?>