<?php
  $cic_menu = ($vars['page']['cic_menu']) ? TRUE : FALSE;
  $menu = ($cic_menu) ? 'cic-menu' : 'mobile-menu';
  $menu_inner = ($cic_menu) ? 'cic-menu-inner' : 'mobile-menu-inner';
?>

<nav id="<?php print $menu; ?>" class="menu">
  <div class="<?php print $menu_inner; ?>">
    <?php print render($vars['page']['trans_left_drawer']); ?>
  </div>
</nav>
