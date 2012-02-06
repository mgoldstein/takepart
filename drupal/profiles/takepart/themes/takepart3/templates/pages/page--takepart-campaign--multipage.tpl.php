
REPLACE THIS HEADER


<div id="page-wrapper" class="multipage-campaign">

  <div id="slim-header" class='clearfix'>
    <div id='logo'><?php print l("", "<front>")?></div>
   
    <div class="clearfix" id="nav-wrap">
    
      <?php if ($page['header']): ?>
        <div id='header' class='clear clearfix'>
          <?php print render($page['header']); ?>
        </div>
      <?php endif; ?>
    </div>
   	
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
  </div>


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
  
  <div id='page' class='clear page clearfix <?php print $multipage_class; ?> <?php print render($node->type); ?>'>
  
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
  
 <?php print $footer ?>
 
 </div>
