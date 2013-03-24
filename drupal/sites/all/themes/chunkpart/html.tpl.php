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

  <div id="skip-link" class="skip-link">
      <a href="#page"><?= t('Skip to main content') ?></a>
  </div>

  <header id="site-header">
    <p id="logo">
      <img src="<?=theme_get_setting('logo')?>" alt="TakePart logo" />
    </p>

    <nav id="user-nav">
      <?=render($user_nav) ?>
    </nav>

    <nav id="main-menu-nav">
      <?=render(menu_tree('main-menu')) ?>
    </nav>

    <nav id="menu-reel-impact-nav">
      <?=render(menu_tree('menu-reel-impact')) ?>
    </nav>

    <nav id="menu-hot-topics-nav">
      <?=render(menu_tree('menu-hot-topics')) ?>
    </nav>

    <nav id="menu-don-t-miss-nav">
      <p><?=t('Don\'t Miss:') ?></p>
      <?=render(menu_tree('menu-don-t-miss')) ?>
    </nav>

    <?=drupal_render(module_invoke('search_api_page', 'block_view', '2')) ?>
  </header>

  <? if (isset($page_top)): ?>
      <?=$page_top ?>
  <? endif ?>

<? listArrayRecursive(&$variables, '$variables'); ?>

  <? if (isset($page)): ?>
      <?=$page ?>
  <? endif ?>      

  <? if (isset($custom)): ?>
      <?=$custom ?>
  <? endif ?>        

  <?php print $scripts; ?>

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
