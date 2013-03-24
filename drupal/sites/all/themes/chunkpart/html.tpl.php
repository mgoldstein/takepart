<!-- old template -->
<!doctype html>
<html lang="<?=$language->language ?>" dir="<?=$language->dir ?>"<?=$rdf_namespaces ?> >
<head profile="<?=$grddl_profile ?>">
  <title><?=$head_title ?></title>
  <?=$head ?>
  <meta name="viewport" content="width=device-width">
  <?=$styles ?>
  <!--[if lt IE 9]>
      <script src="/profiles/takepart/themes/takepart3/js/html5shiv.js"></script>
  <![endif]-->
</head>
<body class="<?=$classes ?>" <?=$attributes ?>>

  <? if (isset($page_top)): ?>
      <?=$page_top ?>
  <? endif ?>

  <? if (isset($page)): ?>
      <?=$page ?>
  <? endif ?>      

  <? if (isset($custom)): ?>
      <?=$custom ?>
  <? endif ?>        

  <?=$scripts ?>

  <? if (isset($page_bottom)): ?>
      <?=$page_bottom ?>
  <? endif ?>

  <? if (isset($tp_sysinfo_comment_tags)): ?>
      <?=$tp_sysinfo_comment_tags ?>
  <? endif ?>
</body>
</html>

<!-- /old template -->

<? /*
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
*/ ?>
