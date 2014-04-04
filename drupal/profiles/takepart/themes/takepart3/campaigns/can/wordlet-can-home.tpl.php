<div class="content">
	<div class="primary">
		<div class="headline">
			<h2><?=w('headline')?></h2>
		</div>
		<div class="body cms">
			<?=w('body')?>
		</div>
		<div class="chapter-menu" <?=wa('chapters')?>>
			<? foreach( wl('chapters') as $w ): ?>
				<a class="chapter <?=$w->token?>" href="<?=wu('can_home')?>#<?=$w->token?>" data-chapter='<?=$w->token?>'>
					<img src="<?=$w->img_src?>" alt="See the <?=$w->single(false)?> chapter">
					<? foreach( wl($w->token . '_see_button') as $w2 ): ?>
					<span class="button" <?=wa($w->token . '_see_button')?>><?=$w2->single(false)?></span>
					<? endforeach ?>
				</a>
			<? endforeach ?>
		</div>
		<div class="chapters">
			<? foreach( wl('chapters') as $w ): ?>
			<div id="<?=$w->token?>" class='chapter <?=$w->token?>' <?=wa('chapters')?>>
				<div class="header">
					<? $w2 = w($w->token . '_headline') ?>
					<h3 <?=wa($w->token . '_headline')?>><?=$w2->single(false)?></h3>
					<? $w2 = w($w->token . '_vote_button') ?>
					<? if ($w2->active): ?>
					<div class="vote-wrapper">
						<a href='vote_<?=w($w->token)?>' class="vote" <?=wa($w->token . '_vote_button')?>><?=$w2->single(false)?></a>
						<div class="modal-wrapper">
							<div class="modal vote-form">
								<? $w2 = w($w->token . '_confirm_modal') ?>
								<h4 class='title'><?=$w2->single(false)?></h4>
								<div class='cms modal-content'><?=$w2->multi(false)?></div>
								<div class="cms vote-form-wrapper">
									<?=w($w->token . '_vote_form')?>
								</div>
								<span class='cancel'>Cancel</span>
							</div>

							<div class="modal thank-you">
								<? $w2 = w($w->token . '_thank_you_modal') ?>
								<h4 class='title'><?=$w2->single(false)?></h4>
								<div class='cms modal-content'><?=$w2->multi(false)?></div>
				                <? $w2 = w($w->token.'_add_this'); ?>
				                <div class="addThis"
				                    data-message="<?=$w2->multi(false)?>"
				                    data-url="<?=$w2->href?>">
				                    <a class="addthis_button_facebook at300b" title="Facebook" href="#"><img src="/profiles/takepart/modules/takepart_addthis/images/ta_fb_share.png" alt="Share on Facebook"></a>
				                    <a class="addthis_button_twitter at300b" title="Tweet" href="#"><img src="/profiles/takepart/modules/takepart_addthis/images/ta_twitter_share.png" alt="Share on Twitter"></a>
				                    <a class="addthis_button_email at300b" title="Email" href="#"><img src="/profiles/takepart/modules/takepart_addthis/images/ta_email_share.png" alt="Share by Email"></a>
				                </div>
							</div>

							<div class="modal voting-rejected">
								<? $w2 = w('rejected_modal') ?>
								<h4 class='title'><?=$w2->single(false)?></h4>
								<div class='cms modal-content'><?=$w2->multi(false)?></div>
							</div>

							<div class="modal voting-error">
								<? $w2 = w('error_modal') ?>
								<h4 class='title'><?=$w2->single(false)?></h4>
								<div class='cms modal-content'><?=$w2->multi(false)?></div>
							</div>
						</div>
					</div>
					<?endif?>
				</div>
				<div class="chapter-info" <?=wa($w->token . '_sections')?>>
					<div class="section-menu">
						<? foreach( wl($w->token . '_sections') as $w2 ): ?>
							<a class="section" href="<?=wu('can_home')?>#<?=$w2->token?>">
								<img src="<?=$w2->img_src?>" alt="Student portrait">
							</a>
						<? endforeach ?>
					</div>
					<div class="sections">
					<? foreach( wl($w->token . '_sections') as $w2 ): ?>
						<div id="<?=$w2->token?>" class="section">
							<? if($w2->video): ?>
							<div class="video-wrapper">
								<div class="video">
								<script type="text/x-javascript-template" class="video-template">
									<iframe class="video-player" width="515" height="315" src="//www.youtube.com/embed/<?=$w2->video?>" frameborder="0" allowfullscreen></iframe>
								</script>
								</div>
								<div class="info cms">
									<span class="headline"><?=$w2->single(false)?></span>
									<?=$w2->multi(false)?>
								</div>
							</div>
							<? elseif( w($w->token . "_" . $w2->token . "_snap_gallery")->single(false) != "" ): ?>
							<div class="snap-gallery" <?=wa($w->token . "_" . $w2->token."_snap_gallery")?>>
								<!-- SnapWidget -->
								<iframe allowtransparency="true" frameborder="0" scrolling="no"
								src="//snapwidget.com/p/widget/?id=<?=w($w->token . "_" . $w2->token . "_snap_gallery")->single(false)?>"
								style="border:none; overflow:hidden; width:495px; height: 365px"></iframe>
							</div>
							<? else: ?>
							<div class="article-wrapper cms">
								<span class="headline"><?=$w2->single(false)?></span>
								<?=$w2->multi(false)?>
							</div>
							<? endif ?>
							<? if ( wordlet_edit_mode() ): ?>
								<p <?=wa($w->token . "_" . $w2->token."_snap_gallery")?>>Edit <?=$w->token?> <?=$w2->token?> Snap Gallery</p>
								<p>Note: section will load video type if section->video exists. if it doesn't and a snap gallery exists it will load that. else it will use the section's multi as an article type.</p>
							<? endif ?>
						</div>
					<? endforeach ?>
					</div>
				</div>

				<? if ( wordlet_edit_mode() ): ?>
					<p <?=wa($w->token . '_headline')?>>Edit <?=$w->token?> Headline</p>
					<p <?=wa($w->token . '_vote_button')?>>Edit <?=$w->token?> Vote Button</p>
					<p <?=wa('fb_signup_modal')?>>Edit Facebook Connect Modal</p>
					<p <?=wa($w->token . '_confirm_modal')?>>Edit <?=$w->token?> Confirm Modal</p>
					<p <?=wa($w->token . '_vote_form')?>>Edit <?=$w->token?> Vote Form</p>
					<p <?=wa($w->token . '_thank_you_modal')?>>Edit <?=$w->token?> Thank You Modal</p>
					<p <?=wa($w->token.'_add_this')?>>Edit <?=$w->token?> Add This Block</p>
					<p <?=wa('rejected_modal')?>>Edit Rejected Modal</p>
					<p <?=wa('error_modal')?>>Edit Error Modal</p>
				<? endif ?>

			</div>
			<? endforeach ?>
		</div>
	</div>
</div>