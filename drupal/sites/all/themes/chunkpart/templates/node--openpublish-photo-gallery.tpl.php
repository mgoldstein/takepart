<div id="gallery-main" class="<?=!$node->status ? 'unpublished':'' ?>">
	<? if ( _s($node, 'field_display_cover') ): ?>
		<article id="gallery-cover">
			<div id="gallery-cover-main">
				<aside id="gallery-cover-social" class="social">
					<h3 class="headline"><?=t('Share Gallery') ?></h3>
					<div class="tp-social" id="gallery-cover-share"></div>
				</aside>
				<a href="#gallery-photos" class="enter-link">
					<p class="image">
						<?=_simage($node, 'field_thumbnail', 'node', 'tp_gallery_slide') ?>
					</p>
					<div class="content">
						<p class="description"><?=t('Photo Gallery') ?></p>
						<h1 class="headline"><?=_s($node->title) ?></h1>
						<p class="enter"><?=t('Enter Photo Gallery') ?></p>
					</div>
				</a>
			</div>

			<div id="gallery-cover-content">
				<? if ( $body = _snode($node, 'body') ): ?>
					<div id="gallery-body" class="cms">
						<div class="content">
							<?=_s($body)?>
						</div>
					</div>
				<? endif ?>

				<footer>
					<nav id="gallery-tags" class="page-tags">
						<h3 class="headline">
							<?=t('Get More:') ?>
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

					<div id="gallery-comments">
						<?=drupal_render(module_invoke('comment_block_simple', 'block_view', 'comment_block')) ?>
					</div>
				</footer>
			</div>
		</article>
	<? endif ?>

	<article id="gallery-photos">
		<header id="gallery-header">
			<div id="gallery-header-main">
				<h1 class="headline"><?=_s($node->title) ?></h1>
				<? /* <p id="gallery-abstract"><?=_s($node, 'field_subhead') ?></p> */ ?>
				<div class="header-secondary">
					<p class="date"><?=date('F j, Y', $node->created)?></p>

					<? if ( $authors = _snode($node, 'field_author') ): ?>
						<ul class="author-names">
							<? while ( list($key, $author) = _seach($authors) ): ?>
								<li class="<?=($key == 0)?'first-child':''?> <?=($key == count($field_author) - 1)?'last-child':''?>">
									<a href="<?=_surl($author)?>" rel="author"><?=$author->title ?></a>
								</li>
							<? endwhile ?>
						</ul>
					<? endif ?>
				</div>

				<aside id="gallery-cover-social" class="social">
					<h3 class="headline"><?=t('Share Gallery') ?></h3>
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
			<ul>
				<? if ( $images = _snode($node, 'field_gallery_images') ): ?>
					<? while ( list($key, $image) = _seach($images) ): ?>
						<li class="slide<?=$key ?> gallery-slide" data-token="<?=_takepart_galleries_get_token(_s($image['file'], 'field_image_title', 'file'), $image['file']->filename) ?>">
							<figure>
								<div class="image">
									<?=_simage($image, null, null, 'tp_gallery_slide') ?>
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
					<li id="next-gallery" data-token="next-gallery">
						<a href="<?=$next_gallery->href ?>" class="enter-link">
							<div class="image-area">
								<div class="image-area-inner">
									<p class="image"><?=_simage($next_gallery->node, 'field_thumbnail', 'node', 'tp_gallery_slide') ?></p>
									<div class="content">
										<p class="description"><?=t('Up Next') ?></p>
										<h2 class="headline"><?=_s($next_gallery->title) ?></h2>
										<p class="enter"><?=t('Enter Photo Gallery') ?></p>
									</div>
								</div>
							</div>

							<div class="photo-caption">
								<div class="caption cms">
									<?=_s($next_gallery->node, 'body')?>
								</div>
							</div>
						</a>
					</li>
				<? endif ?>
			</ul>
		</div>

		<footer id="gallery-footer">
			<? if ( $relateds = field_get_items('node', $node, 'field_related_stories') ): ?>
				<nav id="gallery-related">
					<h3><?=t('Related stories on TakePart:') ?></h3>
					<ul>
						<? while ( list($key, $related) = _seach($relateds) ): ?>
							<li><a href="<?=_surl($related) ?>"><?=$related->title ?></a></li>
						<? endwhile ?>
					</ul>
				</nav>
			<? endif ?>

			<? // Do we _need_ to copy these? ?>
			<nav class="page-tags">
				<h3 class="headline">
					<?=t('Get More:') ?>
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

			<div class="gallery-comments">
				<?=drupal_render(module_invoke('comment_block_simple', 'block_view', 'comment_block')) ?>
			</div>
		</footer>
	</article>
</div>