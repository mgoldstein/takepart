<article id="gallery-main" class="article <?=!$node->status ? 'unpublished':'' ?>"
	<? if ( $series = _snode($node, 'field_series') ): ?>
		<? while ( list($key, $serie) = _seach($series) ): ?>
			data-series="<?=htmlspecialchars($serie->name) ?>"
		<? endwhile ?>
	<? endif ?>
	>
	<? if ( _s($node, 'field_display_cover') ): ?>
		<div id="gallery-cover">
			<div id="gallery-cover-main">
				<aside id="gallery-cover-social" class="social">
					<h3 class="headline"><?=t('Share Gallery') ?></h3>
					<div class="tp-social" id="gallery-cover-share"></div>
				</aside>

				<a href="#gallery-photos" class="enter-link image-content-wrapper">
					<p class="image">
						<? if ( $node->field_gallery_main_image ): ?>
							<?=_simage($node, 'field_gallery_main_image', 'node', 'tp_gallery_slide') ?>
						<? else: ?>
							<?=_simage($node, 'field_thumbnail', 'node', 'tp_gallery_slide') ?>
						<? endif ?>
					</p>
					<div class="content">
						<div class="content-inner">
							<p class="description"><?=t('Photo Gallery') ?></p>
							<h1 class="headline"><?=_s($node->title) ?></h1>
						</div>
						<p class="enter"><?=t('Enter Photo Gallery') ?></p>
					</div>
				</a>

			</div>
		</div>
	<? endif ?>

	<div id="gallery-photos">
		<header id="gallery-header">
			<div id="gallery-header-main" class="article-header">
				<h1 class="article-headline"><?=_s($node->title) ?></h1>
				<? if ( $subhead = _snode($node, 'field_subhead') ): ?>
					<p class="article-abstract"><?=_s($subhead) ?></p>
				<? endif ?>
				<div class="header-secondary">
					<p class="pubdate"><?=date('F j, Y', $node->created)?></p>

					<? if ( $authors = _snode($node, 'field_author') ): ?>
						<address class="authors">
							<? while ( list($key, $author) = _seach($authors) ): ?>
								<span class="author <?=($key == 0)?'first-child':''?> <?=($key == count($field_author) - 1)?'last-child':''?>">
									<a href="<?=_surl($author)?>" rel="author"><?=$author->title ?></a>
								</span>
							<? endwhile ?>
						</address>
					<? endif ?>
				</div>

				<aside id="gallery-cover-social" class="social">
					<h3 class="headline"><?=t('Share Photo') ?></h3>
					<div class="tp-social" id="gallery-cover-share"></div>
				</aside>
			</div>

			<? if ( $field_topic_box = _snode($node, 'field_topic_box') ): ?>
				<aside id="topic_box">
					<ul>
						<? while ( list($key, $topic) = _seach($field_topic_box) ): ?>
							<li>
								<? if ( $link = _slink($topic, 'field_topic_box_link') ): ?>
									<a href="<?=($link['url'])?$link['url']:'#' ?>">
										<?=_simage($topic, 'field_topic_box_image') ?>
									</a>
								<? else: ?>
									<?=_simage($topic, 'field_topic_box_image') ?>
								<? endif ?>
							</li>
						<? endwhile ?>
					</ul>
				</aside>
			<? endif ?>
		</header>

		<div id="gallery-content">
			<ul data-tpslide_separator="<?=t(' of ') ?>" data-tpslide_previous="<?=t('Previous Slide')?>" data-tpslide_next="<?=t('Next Slide')?>">
				<? if ( $images = _snode($node, 'field_gallery_images') ): ?>
					<? while ( list($key, $image) = _seach($images) ): ?>
						<li class="slide<?=$key ?> gallery-slide" data-token="<?=_takepart_galleries_get_token(_s($image['file'], 'field_image_title', 'file'), $image['file']->filename) ?>">
							<figure>
								<div class="image-content-wrapper">
									<div class="image">
										<?=_simage($image, null, null, 'tp_gallery_slide') ?>
									</div>
								</div>
								<figcaption class="photo-caption">
									<h2 class="headline"><?=_s($image['file'], 'field_image_title', 'file') ?></h2>
									<div class="caption cms">
										<?=_s($image['file'], 'field_media_caption', 'file') ?>
									</div>
								</figcaption>
							</figure>
						</li>
					<? endwhile ?>
				<? endif ?>
				<? if ( $next_gallery ): ?>
					<li id="next-gallery" data-token="next-gallery" class="next-article">
						<section class="enter-link">
							<div class="image-content-wrapper">
								<div class="image-area-inner">
									<a href="<?=$next_gallery->href ?>/first-slide">
										<p class="image">
											<? if ( $next_gallery->node->field_gallery_main_image ): ?>
												<?=_simage($next_gallery->node, 'field_gallery_main_image', 'node', 'tp_gallery_slide') ?>
											<? else: ?>
												<?=_simage($next_gallery->node, 'field_thumbnail', 'node', 'tp_gallery_slide') ?>
											<? endif ?>
										</p>
										<div class="content">
											<div class="content-inner">
												<p class="description"><?=t('Up Next') ?></p>
												<h2 class="headline"><?=_s($next_gallery->title) ?></h2>
											</div>
											<p class="enter"><?=t('Enter Photo Gallery') ?></p>
										</div>
									</a>
								</div>
							</div>

							<div class="photo-caption">
								<div class="caption cms">
									<p class="headline"><?=_s($next_gallery->title) ?></p>
									<? if ( $field_topic = _snode($next_gallery->node, 'field_topic') ): ?>
										<? while ( list($key, $tag) = _seach($field_topic) ): ?>
											<p class="topic"><?=$tag->name ?></p>
										<? endwhile ?>
									<? endif ?>

									<? if ( $nextbody = _snode($next_gallery->node, 'body', 'node') ): ?>
										<?=_s($nextbody)?>
									<? elseif ( $nextsubhead = _snode($next_gallery->node, 'field_subhead', 'node') ): ?>
										<h3 class="article-abstract"><?=_s($nextsubhead) ?></h3>
									<? endif ?>
								</div>
							</div>
						</section>
					</li>
				<? endif ?>
			</ul>

			<? if ( _s($node, 'field_display_cover') ): ?>
				<p class="back-to-cover">
					<a href="#gallery-cover"><?=t('Back to cover')?></a>
				</p>
			<? endif ?>
			<? if ( $next_gallery ): ?>
				<p class="forward-to-gallery">
					<a href="<?=$next_gallery->href ?>#first-slide"><?=t('Next photo gallery:')?> <?=_s($next_gallery->title) ?></a>
				</p>
			<? endif ?>
		</div>
	</div>

	<div id="gallery-related">
		<div id="gallery-description">
			<? if ( $body = _snode($node, 'body') ): ?>
				<div id="gallery-body" class="cms">
					<div class="content">
						<?=_s($body)?>
					</div>
					<p class="enter-link"><a href="#gallery-photos">Enter Photo Gallery</a></p>
				</div>
			<? endif ?>
		</div>

		<? if ( _s($node, 'field_display_tab_banner') ): ?>
			<div class="takepart-take-action-widget"></div>
		<? endif ?>

		<? if ( $relateds = field_get_items('node', $node, 'field_related_galleries') ): ?>
			<nav id="related-galleries" class="related">
				<h3 class="headline"><?=t('Related galleries') ?></h3>
				<ul>
					<? while ( list($key, $related) = _seach($relateds) ): ?>
						<li><a href="<?=_surl($related) ?>">
							<?=_simage($related, 'field_thumbnail', 'node', 'tp_300x185') ?>
							<?=$related->title ?>
						</a></li>
					<? endwhile ?>
				</ul>
			</nav>
		<? endif ?>

		<? if ( $relateds = field_get_items('node', $node, 'field_related_stories') ): ?>
			<nav class="related related-stories">
				<h3 class="headline"><?=t('Related stories on TakePart') ?></h3>
				<ul>
					<? while ( list($key, $related) = _seach($relateds) ): ?>
						<li><a href="<?=_surl($related) ?>"><?=$related->title ?></a></li>
					<? endwhile ?>
				</ul>
			</nav>
		<? endif ?>

		<nav id="gallery-tags" class="page-tags">
			<h3 class="headline">
				<?=t('Get More') ?>
			</h3>

			<ul>
				<? if ( $field_topic = _snode($node, 'field_topic') ): ?>
					<? while ( list($key, $tag) = _seach($field_topic) ): ?>
						<li><a href="<?=_surl($tag) ?>"><?=$tag->name ?></a></li>
					<? endwhile ?>
				<? endif ?>

				<? if ( $field_free_tag = _snode($node, 'field_free_tag') ): ?>
					<? while ( list($key, $tag) = _seach($field_free_tag) ): ?>
						<li><a href="<?=_surl($tag) ?>"><?=$tag->name ?></a></li>
					<? endwhile ?>
				<? endif ?>
			</ul>
		</nav>

		<!-- outbrain analytics snippet -->
		<div class="OUTBRAIN" data-src="<?=_surl($node) ?>" data-widget-id="TR_1" data-ob-template="TakePart" ></div>
		<script type="text/javascript" async="async" src="http://widgets.outbrain.com/outbrain.js"></script>

		<!-- taboola widgets -->

		<h3 style="font-size: 20px; margin-bottom: 4px; text-transform: uppercase; font-family: TradeGothicLTStdCnBold, sans-serif;">Takepart's Most Popular</h3>
		<div id='taboola-bottom-main-column-mix'></div>
		<script type="text/javascript">
		window._taboola = window._taboola || [];
		_taboola.push({mode:'thumbs-1r-organic', container:'taboola-bottom-main-column-mix', placement:'bottom-main-column', target_type:'mix'});
		</script>


		<? if ( isset($node_region['bean_on-our-radar-block']) ): ?>
			<?=render($node_region['bean_on-our-radar-block']) ?>
		<? endif ?>

		<div class="gallery-comments">
			<?=drupal_render(module_invoke('comment_block_simple', 'block_view', 'comment_block')) ?>
		</div>
	</div>
</article>