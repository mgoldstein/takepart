<div class="content">
	<h4 class="call-to-share"><?=w('social_follow_body')?></h4>
	<h2 class="content-header"><span><?=w('page_title')?></span></h2>
  <div class="main-video-wrapper" <?=wa('video')?>>
      <script src="<?=w('video')?>"></script>
  </div>
	<section class="social-menu">
		<? include('partials/teach-social-block.tpl.php') ?>
	</section>
	<section class="page-body-content cms">
		<?= w('page_body_content') ?>
    <? include('partials/teach-watch-promo.tpl.php') ?>
	</section>
</div>
<br clear="all" />