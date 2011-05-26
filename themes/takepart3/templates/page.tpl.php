<?php if ($page['help'] || ($show_messages && $messages)): ?>
  <div id='console'><div class='limiter clearfix'>
    <?php print render($page['help']); ?>
    <?php if ($show_messages && $messages): print $messages; endif; ?>
  </div></div>
<?php endif; ?>

<?php if ($page['header']): ?>
  <div id='header' class='clearfix'>
    <?php print render($page['header']); ?>
  </div>
<?php endif; ?>

<div id='nav-wrap' class='clear clearfix'>
  <?php if (isset($main_menu)) : ?>
    <?php print theme('links', array('links' => $main_menu, 'attributes' => array('class' => 'links main-menu'))) ?>
  <?php endif; ?>
  <?php if (isset($secondary_menu)) : ?>
    <?php print theme('links', array('links' => $secondary_menu, 'attributes' => array('class' => 'links secondary-menu'))) ?>
  <?php endif; ?>
</div>

<?php if ($page['highlighted']): ?>
  <div id='highlighted'><div class='limiter clearfix'>
    <?php print render($page['highlighted']); ?>
  </div></div>
<?php endif; ?>

<div id='page' class='page clearfix'>

  <?php if ($page['sidebar_first']): ?>
    <div id='left' class='clearfix'><?php print render($page['sidebar_first']) ?></div>
  <?php endif; ?>

  <div class='main-content'>
    <?php if ($breadcrumb) print $breadcrumb; ?>
    <?php if ($title): ?><h1 class='page-title'><?php print $title ?></h1><?php endif; ?>
    <?php if ($primary_local_tasks): ?><ul class='links clearfix'><?php print render($primary_local_tasks) ?></ul><?php endif; ?>
    <?php if ($secondary_local_tasks): ?><ul class='links clearfix'><?php print render($secondary_local_tasks) ?></ul><?php endif; ?>
    <?php if ($action_links): ?><ul class='links clearfix'><?php print render($action_links); ?></ul><?php endif; ?>
    <div id='content' class='clearfix'><?php print render($page['content']) ?></div>
  </div>

  <?php if ($page['sidebar_second']): ?>
    <div id='right-rail' class='clearfix'><?php print render($page['sidebar_second']) ?></div>
  <?php endif; ?>

</div>

<div id="footer" class='clear'>
  <?php print render($page['footer']) ?>
</div>
