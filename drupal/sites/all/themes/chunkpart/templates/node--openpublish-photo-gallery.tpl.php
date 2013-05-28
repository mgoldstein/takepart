<!-- Gallery start -->

<div id="gallery-main" class="<?=!$node->status ? 'unpublished':'' ?>">
	<article id="gallery-cover">
		<aside id="gallery-cover-social" class="social">
			<h3 class="headline"><?=t('Share Gallery') ?></h3>
			<div class="tp-social" id="gallery-cover-share"></div>
		</aside>
		<div id="gallery-cover-main">
			<p class="image">
				<?=_simage($node, 'field_thumbnail') ?>
			</p>
			<div class="content">
				<p class="description"><?=t('Photo Gallery') ?></p>
				<h1 class="headline"><?=_s($node->title) ?></h1>
				<p class="enter"><a href="#gallery-photos"><?=t('Enter Photo Gallery') ?></a></p>
			</div>
		</div>

		<? if ( $body = _snode($node, 'field_body') ): ?>
			<div id="gallery-body" class="cms">
				<?=_s($body)?>
			</div>
		<? endif ?>

		<footer>
			<nav id="gallery-tags">
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
	</article>

	<article id="gallery-photos">
		<header id="gallery-header">
			<h1 class="headline"><?=_s($node->title) ?></h1>
			<? /* <p id="gallery-abstract"><?=_s($node, 'field_subhead') ?></p> */ ?>
			<div class="secondary">
				<p id="gallery-date"><?=date('F j, Y', $node->created)?></p>

				<ul id="gallery-author-names">
					<? if ( $authors = _snode($node, 'field_author') ): ?>
						<? while ( list($key, $author) = _seach($authors) ): ?>
							<li class="<?=($key == 0)?'first-child':''?> <?=($key == count($field_author) - 1)?'last-child':''?>">
								<a href="<?=_surl($author)?>" rel="author"><?=$author->title ?></a>
							</li>
						<? endwhile ?>
					<? endif ?>
				</ul>
			</div>

			<aside id="gallery-cover-social" class="social">
				<h3 class="headline"><?=t('Share Gallery') ?></h3>
				<div class="tp-social" id="gallery-cover-share"></div>
			</aside>

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
						<li class="slide<?=$key ?>" data-token="<?=_takepart_galleries_get_token(_s($image['file'], 'field_image_title', 'file'), $image['file']->filename) ?>">
							<figure>
								<?=_simage($image) ?>
								<figcaption>
									<h2 class="headline"><?=_s($image['file'], 'field_image_title', 'file') ?></h2>
									<div class="caption">
										<?=_s($image['file'], 'field_media_caption', 'file') ?>
									</div>
								</figcaption>
							<figure>
						</li>
					<? endwhile ?>
				<? endif ?>
				<? if ( $next_gallery ): ?>
					<li id="next-gallery">
						<a href="<?=$next_gallery->href ?>">
							<p class="image"><?=_simage($next_gallery->node, 'field_thumbnail') ?></p>
							<div class="content">
								<p class="description"><?=t('Up Next') ?></p>
								<h2><?=_s($next_gallery->title) ?></h2>
								<p class="enter"><?=t('Enter Photo Gallery') ?></p>
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
		</footer>
	</article>
</div>

<!-- /Gallery start -->