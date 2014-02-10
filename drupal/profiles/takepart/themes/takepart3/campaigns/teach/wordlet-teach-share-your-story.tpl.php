<div id="sys-form-content" class="content teach-sys-content">
    <div class="row">
        <div class="col-1-2">
            <h1 class="sys-headline"><?php print w('page_headline'); ?></h1>
            <p><?php print w('intro_body'); ?></p>
            <?php include('partials/teach-sys-form.tpl.php'); ?>
        </div>
        <div class="col-1-2">
            <aside class="sys-update">
                <h2><span>The Teach Fund</span> <span><?php print w('update_count'); ?></span> <span>and counting</span></h2>
                <p><?php print w('update_body'); ?></p>
            </aside>
            <aside class="sys-tips">
                <h2><?php print w('tips_headline'); ?></h2>
                <p><?php print w('tips_body'); ?></p>
            </aside>
        </div>
    </div>
</div>
<div id="sys-coppa-content" class="content teach-sys-content initially-hidden">
    <p>COPPA ERROR MESSAGE</p>
</div>
<div id="sys-thanks-content" class="content teach-sys-content initially-hidden">
    <p>THANK YOU MESSAGE</p>
</div>
