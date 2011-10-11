<div id="page-wrapper">
  <?php if ($is_multipage): ?>
  <div id="slim-header" class='clearfix'>
    <ul id="top-follow">
       <li class="fb"><a href="http://www.facebook.com/takepart">facebook</a></li>
      <li class="twitter"><a href="http://www.twitter.com/takepart">twitter</a></li>
    </ul><!--/top follow-->
    <div id="join-login-top">
      <div class="login-fb clearfix">
        <?php print $user_nav; ?>       
      </div> 
    </div><!--/join-login-top-->
    <div class="clear clearfix" id="nav-wrap">
      <div id='logo'><?php print l("", "<front>")?></div>
      <?php print $top_nav ?>
    </div>
  </div>
  <?php else: ?>
  <div id="header" class='clearfix'>
    <div id='slim-logo'><?php print l("", "<front>")?></div>


 
  <div class="clearfix" id="nav-wrap">
    <?php print $top_nav ?>
  
  </div><!--/nav-wrap-->
  
  	<div id="top-search">
      <div class="tpform-item"><?php print drupal_render($search_takepart_form); ?></div>
  	</div><!--/top search-->
			  		<div id="join-login-top">
      <div class="login-fb clearfix">
        <?php print $user_nav; ?>  			
      </div> 
  	</div><!--/join-login-top-->  


  	  	<ul id="top-follow">
								<li class="fb"><a target = '_blank' href="http://www.facebook.com/takepart">facebook</a></li>
				<li class="twitter"><a target = '_blank' href="http://www.twitter.com/takepart">twitter</a></li>
				<li class="youtube"><a target = '_blank' href="http://www.youtube.com/takepart">youtube</a></li>
				<li class="rss"><a href="rss">rss</a></li>
			</ul><!--/top follow-->
			
 </div><!--/header-->
  
  <?php endif; ?>

  <?php if ($page['help'] || ($show_messages && $messages)): ?>
    <div id='console'><div class='limiter clearfix'>
      <?php print render($page['help']); ?>
      <?php if ($show_messages && $messages): print $messages; endif; ?>
    </div></div>
  <?php endif; ?>



  
  <?php if ($page['highlighted']): ?>
    <div id='highlighted'><div class='clear limiter clearfix'>
      <?php print render($page['highlighted']); ?>
    </div></div>
  <?php endif; ?>
  
  <div id='page' class='clear page clearfix <?php print $multipage_class; ?>'>
  
    <div class='main-content'>
      <?php  /* if ($title): ?><h1 class='page-title'><?php print $title ?></h1><?php endif; */ ?>
      <?php if (isset($primary_local_tasks)): ?><ul class='links clearfix'><?php print render($primary_local_tasks) ?></ul><?php endif; ?>
      <?php if (isset($secondary_local_tasks)): ?><ul class='links clearfix'><?php print render($secondary_local_tasks) ?></ul><?php endif; ?>
      <?php if ($action_links): ?><ul class='links clearfix'><?php print render($action_links); ?></ul><?php endif; ?>
      <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
        
      <?php print render($page['content_top']); ?>
      
      <div id='content' class='clearfix'>
        <?php print render($page['content']) ?>
      </div>
      
      <?php if ($page['sidebar_first']): ?>
        <div id='left-rail' class='clearfix'><?php print render($page['sidebar_first']) ?></div>
      <?php endif; ?>
      
      
      <?php print render($page['content_bottom']); ?>
      
    </div>
    
    <?php if ($page['sidebar_second']): ?>
      <div id='right-rail' class='clearfix'><?php print render($page['sidebar_second']) ?></div>
    <?php endif; ?>
  
  </div>
  
  <div id="footer" class='clear'>
    <?php print render($page['footer']) ?>
    <ul id="campaign-links">
    	<li><a href="http://www.climatecrisis.net/" id="climate-crisis">Climate Crisis</a></li>
        <li><a href="http://www.savemyoceans.com/" id="save-my-oceans">Save My Oceans</a></li>
        <li><a href="http://www.foodincmovie.com/" id="hungry-for-change">Hungry For Change</a></li>
        <li><a href="http://www.waitingforsuperman.com/action/" id="waiting-for-superman">Waiting For Superman</a></li>
    </ul>
    <div id="our-film-campaigns" class="footer-column-wrapper clearfix">
      <div class="column title">
        <a href="#">our film campaigns</a>
      </div><!--/column-->
      <?php print $film_camp_nav ?>
     </div>
     <div id="friends-of-takepart" class="footer-column-wrapper clearfix">
      <div class="column title">
        <a href="#">friends of takepart</a>
      </div><!--/column-->
      <?php print $friends_takepart_nav ?>
    </div>
    
    <div id="footer-set-links" class="footer-column-wrapper clearfix">
      <div class="column title">
        <a href="#">Topics</a>
      </div><!--/column-->
      <?php print $takepart_topics_nav ?>
    </div>
    <div id="footer-links" class="clear clearfix">
      <ul class="clearfix" id="soc-links">
        <li id="fb">  <a target="_blank" href="http://www.facebook.com/takepart">facebook</a></li>
        <li id="twitter"> <a target="_blank" href="http://www.twitter.com/takepart">twitter</a></li>
      </ul>
      <!-- These should be converted to a menu, so TP can manage these links without changing code as they may change from time to time -->
      <ul class="clearfix" id="global-links">
        <li><a href="/about-us">About Us</a></li>
        <li><a href="/contact-us">Contact Us</a></li>
        <li><a href="/help">Help</a></li>
        <li><a href="/privacy-policy">Privacy Policy</a></li>
        <li class="last"><a href="/terms-of-use">Terms of Use</a></li>
      </ul>

    </div>     

    <div id="footer-about">
      <p>TakePart is the Social Action Network&trade; of <a target="_blank" href="http://www.participantmedia.com/">Participant Media</a></p>
      <div id="footer-legal">&copy; 2008-<?php echo date('Y'); ?> TakePart, LLC</div>
    </div>

  </div>
</div>