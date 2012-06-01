<div id="page-wrapper">

<?php print $header ?>
 
  <?php if ($page['highlighted']): ?>
    <div class="clear" id='highlighted'><div class='limiter clearfix'>
      <?php print render($page['highlighted']); ?>
    </div>
  <?php endif; ?>
  
  <?php if ($page['full_width_top']): ?>
      <?php print render($page['full_width_top']); ?>
  <?php endif; ?>
  
  <div id='page' class='page clearfix <?php print $multipage_class; ?> <?php print render($node->type); ?>'>
  
    <div class='main-content'>
      <?php  /* if ($title): ?><h1 class='page-title'><?php print $title ?></h1><?php endif; */ ?>
      <?php if (isset($primary_local_tasks)): ?><ul class='links clearfix'><?php print render($primary_local_tasks) ?></ul><?php endif; ?>
      <?php if (isset($secondary_local_tasks)): ?><ul class='links clearfix'><?php print render($secondary_local_tasks) ?></ul><?php endif; ?>
      <?php if ($action_links): ?><ul class='links clearfix'><?php print render($action_links); ?></ul><?php endif; ?>
      <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
        <?php if ($page['help'] || ($show_messages && $messages)): ?>
          <div id='console'><div class='limiter clearfix'>
          <?php print render($page['help']); ?>
          <?php if ($show_messages && $messages): print $messages; endif; ?>
          </div></div>
        <?php endif; ?> 
         
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
  
   <?php if ($page['full_width_bottom']): ?>
      <?php print render($page['full_width_bottom']); ?>
   <?php endif; ?>
  
<?php print $footer ?>

</div>
