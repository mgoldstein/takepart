<div class="first-block">
    <div class="team-menu">
    <? if ( $teams = wl('teams') ): ?>
        <? foreach ( $teams as $i => $team ): ?>
            <div class="team<?=( ($cur_team == $team->token)?' active':'')?>">
                <? if ( $team_members = wl($team->token.'_team') ): ?>
                    <a class="team-name" href='<?=wu('intelchange_winners_teams')?>?team=<?=$team->token?>'><?=$team->single(false)?></a>
                    <div class="team-members">
                    <? foreach ( $team_members as $i => $team_member ): ?>
                        <a href="<?=wu('intelchange_winners_teams')?>?team=<?=$team->token?>&member=<?=$team_member->token?>" class="member <?=$team_member->token?><?=( ($cur_member == $team_member->token) ?' active':'')?>">
                            <div class="inner-wrapper">
                                <span class="name"><?=strtok($team_member->single(false), " ")?></span>
                                <span class="title"><?=w($team_member->token.'_member_title_label')?></span>
                                <span class="company"><?=w($team->token.'_'.$team_member->token.'_company')?></span>
                            </div>
                        </a>
                    <? endforeach ?>
                    </div>
                <? endif ?>
            </div>
        <? endforeach ?>
    <? endif ?>
    </div>
</div>
<div class="second-block">
    <? if ( ($team = wf('teams', 'token', $cur_team))
        && ($team_member = wf($team->token.'_team', 'token', $cur_member)) ): ?>
    <div class="member" <?=wa($team->token.'_team')?>>
        <div class="first-sub">
            <div class="portrait">
                <img src="<?=$team_member->img_src?>" alt="<?=$team_member->single(false)?>">
            </div>
            <h2 class='headline'>
                <span class='member-title'><?=w($team_member->token.'_member_title_label')?> </span>
                <?=$team_member->single(false)?>
            </h2>
            <div class='facts cms'><?=$team_member->multi_short(false)?></div>
            <div class='blurb cms'><?=$team_member->multi(false)?></div>
            <div class="video">
                <iframe class="video-player" width="675" height="393" src="http://www.youtube.com/embed/<?=$team_member->video?>" frameborder="0" allowfullscreen></iframe>
            </div>
        </div>
        <div class="second-sub">
            <h3 class="subheadline"><?=w('second_block_second_sub_headline')?></h3>
            <a class="gallery" href="<?=w($team->token.'_'.$team_member->token.'_gallery_link')->href?>">
                <div class="image-wrapper" <?=wa($team->token.'_'.$team_member->token.'_gallery_image')?>>
                    <? if ( ($w = w($team->token.'_'.$team_member->token.'_gallery_image')) && $w->img_src ): ?>
                        <img src="<?=$w->img_src?>" alt="<?=$w->single(false)?>" />
                    <? elseif( wordlet_edit_mode() ): ?>
                        Add Image
                    <? endif ?>
                </div>
                <div class="gallery-link-wrapper" <?=wa($team->token.'_'.$team_member->token.'_gallery_link')?>>
                    <div class="gallery-link">
                        <? if ( $link_label = w('gallery_link_label') ): ?>
                            <?=wr($link_label, $team_member)?>
                        <? elseif( wordlest_edit_mode() ): ?>
                            <span <?=wa('gallery_link_label')?>>Add Link Text</span>
                        <? endif ?>
                    </div>

                    <span class="gallery-link"><?=w($team->token.'_'.$team_member->token.'_gallery_link')->single(false)?></span>
                </div>
            </a>
        </div>
        <div class="third-sub">
            <h3 class="subheadline"><?=w('second_block_third_sub_headline')?></h3>
            <div class="entries" <?=wa($team->token.'_'.$team_member->token.'_journal_entries_view')?>>
                <?=w($team->token.'_'.$team_member->token.'_journal_entries_view')?>
            </div>
        </div>
    </div>
    <? endif ?>
</div>