<div id="sys-form-content" class="content teach-story-content teach-sys-content">
    <div class="row">
        <div class="col-1-2">
            <div class="sys-intro">
                <h1 class="sys-headline"><span><?php print w('page_headline'); ?></span></h1>
                <?php print w('intro_body'); ?>
            </div>
            <?php include('partials/teach-sys-form.tpl.php'); ?>
        </div>
        <div class="col-1-2">
            <aside class="sys-update">
		<h2 class=""><span>We're donating more than</span> <span><?php print w('update_count'); ?></span> <span>to schools and classrooms!</span></h2>
                <div class="sys-intro-body"><?php print w('update_body'); ?></div>
            </aside>
            <aside class="sys-tips">
                <h2 class="sys-headline"><span><?php print w('tips_headline'); ?></span></h2>
                <p><?php print w('tips_body'); ?></p>
            </aside>
        </div>
    </div>
</div>
<div id="sys-coppa-content" class="content teach-story-content teach-sys-content teach-sys-coppa-content initially-hidden">
    <h1 class="sys-headline"><span><?php print w('coppa_headline'); ?></span></h1>
    <?php print w('coppa_message'); ?>
</div>
<div id="sys-thanks-content" class="content teach-story-content teach-sys-content teach-sys-thanks-content initially-hidden">
    <h1 class="sys-headline"><span><?php print w('thanks_headline'); ?></span></h1>
    <div><?php print w('thanks_message'); ?></div>
    <?php include('partials/teach-sys-thanks.tpl.php'); ?>
</div>
