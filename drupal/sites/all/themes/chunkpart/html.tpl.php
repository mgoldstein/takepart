<html>
<head>
<title>Article Template</title>
</head>
<body>
<a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
<h1>HTML Template Variables</h1>
<dl>
  <?php foreach(array_keys($variables) as $name): ?>
    <dt><?php print $name; ?></dt>
    <dd><pre><?php
      $repr = print_r($variables[$name], TRUE);
      print htmlentities($repr);
    ?></pre></dd>
  <?php endforeach; ?>
</dl>
<?php
  // As the HTML template is a wrapper, the content it wraps is already rendered
  // in this case the rendered content is in $page
  print $page;
?>
</body>
</html>

