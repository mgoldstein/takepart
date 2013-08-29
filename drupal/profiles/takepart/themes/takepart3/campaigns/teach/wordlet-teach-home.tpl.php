<div class="content">
	<h2 class="content-header"><span><?=w('page_title')?></span></h2>
  <div class="main-video-wrapper" <?=wa('video')?>>
      <script src="<?=w('video')?>"></script>
  </div>
	<section class="social-menu">
		<h4 class="link_on_white"><?=w('social_follow_body')?></h4>
		<? include('partials/teach-social-block.tpl.php') ?>
	</section>
	<section class="page-body-content cms">
		<?= w('page_body_content') ?>
	</section>
</div>
