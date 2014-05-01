<div class="footer-left">
  <div class="footer-menu">
    <span class="footer-title">takepart</span>
    <?php 
    $footer_topics = drupal_render(menu_tree('menu-takepart-topics'));
    if (arg(0) === 'iframes') {
      print str_replace('https://', 'http://', $footer_topics); 
    }
    else {
      print $footer_topics; 
    }
    ?>
  </div>
  <div class="footer-menu">
    <span class="footer-title">films</span>
    <?php 
    $footer_films = drupal_render(menu_tree('menu-takepart-film-campaigns'));
    if (arg(0) === 'iframes') {
      print str_replace('https://', 'http://', $footer_films); 
    }
    else {
      print $footer_films; 
    }
    ?>
    <div class="more">
        <?php 
        $footer_more_films = l('More films', 'film-campaigns', array('attributes' => array('class' => array('more')), 'absolute' => TRUE)); 
        if (arg(0) === 'iframes') {
          print str_replace('https://', 'http://', $footer_more_films); 
        }
        else {
          print $footer_more_films;
        }
        ?> 
    </div>
  </div>
  <div class="footer-menu">
    <span class="footer-title">about takepart</span>
    <?php 
    $corp_links = drupal_render(menu_tree('menu-takepart-links'));
    if (arg(0) === 'iframes') {
      print str_replace('https://', 'http://', $corp_links); 
    }
    else {
      print $corp_links;
    }
    ?>
  </div>
</div>
<div class="footer-right">
  <div class="follow-us">
    <span class="footer-title social">connect</span>
    <?php 
    print drupal_render(menu_tree('menu-social-footer-follow')); 
    ?>
  </div>
  <div class="text">
    <?php 
    if (arg(0) === 'iframes') {
      print str_replace('https://', 'http://', $footer_text); 
    }
    else {
      print $footer_text;
    }
    ?>
  </div>
</div>
<div class="footer-bottom">
  <div class="footer-bottom-inner">
    <span class="footer-title">takepart is a division of participant media:</span> <?php print drupal_render(menu_tree('menu-corporate-footer')); ?>
  </div>
</div>