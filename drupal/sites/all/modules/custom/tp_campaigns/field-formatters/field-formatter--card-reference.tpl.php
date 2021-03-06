<div class="swipe-wrap  <?php print implode(' ', $tray_vars['tray_classes']); ?>">
  <?php print implode('', $tray_vars['cards']); ?>
</div>
<?php print $tray_vars['anchor_tag']; ?>


<?php // Print arrows is multiple cards exist in the card ?>
<?php $reference = field_get_items('node', $variables['entity'], 'field_campaign_card_reference'); ?>
<?php if(!empty($reference) && count($reference) > 1): ?>
  <div class="tray-header">

    <nav class="slider-pagination">
      <div<?php print drupal_attributes(array(
        'class' => array('mobile-arrow','left-arrow'),
        'data-for-tray' => $variables['entity']->title)); ?>
        ><div class="arrow-inner"></div></div>
      <?php for($i = 0; $i < count($items); $i++) : ?>
        <a<?php print drupal_attributes(array(
            'href' => 'javascript:void(0);',
            'data-slide' => $i,
            'data-for-tray' => $variables['entity']->title,
          ));
          ?>><?php print $i; ?></a>
      <?php endfor; ?>
        <div<?php print drupal_attributes(array(
        'class' => array('mobile-arrow','right-arrow'),
        'data-for-tray' => $variables['entity']->title)); ?>
        ><div class="arrow-inner"></div></div>
    </nav>
    <?php if(isset($tray_vars['tray_title']) == true): ?>
      <h1 class="card-title has-instructional"><?php print $tray_vars['tray_title']; ?></h1>
    <?php endif; ?>
  </div>
  <nav class="slider-nav">
    <div class="slider-inner">
      <div<?php print drupal_attributes(array(
        'class' => array('arrow','left-arrow'),
        'data-for-tray' => $variables['entity']->title)); ?>
        ><div class="arrow-inner"></div></div>
      <div<?php print drupal_attributes(array(
        'class' => array('arrow','right-arrow'),
        'data-for-tray' => $variables['entity']->title)); ?>
        ><div class="arrow-inner"></div></div>
    </div>
  </nav>
<?php elseif(!empty($tray_vars['tray_title'])): ?>
  <div class="tray-header">
    <h1 class="card-title"><?php print $tray_vars['tray_title']; ?></h1>
  </div>
<?php endif; ?>