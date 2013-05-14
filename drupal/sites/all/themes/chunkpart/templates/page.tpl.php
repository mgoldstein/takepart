<div id="skip-link" class="skip-link">
    <a href="#main"><?= t('Skip to main content') ?></a>
</div>

<? if ($tabs): ?>
  <div class="tabs-toolbar"><?=render($tabs) ?></div>
<? endif ?>

<?=$header ?>

<main role="main" id="main">
  <div id="site-top">
    <? foreach ( $page['content_top'] as $val ): ?>
      <? if ( ($block = _sblock($val)) ): ?>
        <? // TODO: get the section tag/classes onto blocks ?>
        <?=$block?>
      <? endif ?>
    <? endforeach ?>
  </div>

  <?=render($page['content']) ?>

  <aside id="site-secondary">
    <? foreach ( $page['sidebar_second'] as $val ): ?>
      <? if ( ($block = _sblock($val)) ): ?>
        <? // TODO: get the section tag/classes onto blocks ?>
        <?=$block?>
      <? endif ?>
    <? endforeach ?>
  </aside>
</main>

<?=$footer ?>

<? // TODO: Confirm this block can be here with the site JS below it ?>
<?=render($page['footer']) ?>
