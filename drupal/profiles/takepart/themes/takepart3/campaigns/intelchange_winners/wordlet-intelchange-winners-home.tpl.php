<div class="first-block">
    <div class="intro-block">
        <div class="intro-block-inner">
            <div class="intro-content">
                <div class="intro-image" <?=wa('intro-image')?>>
                    <? if ( ($w = w('intro-image')) && $w->img_src ): ?>
                        <p>
                            <img src="<?=$w->img_src?>" alt="<?=$w->single(false)?>" />
                        </p>
                    <? elseif( wordlet_edit_mode() ): ?>
                        Add Image
                    <? endif ?>
                </div>
                <div class="intro-text">
                    <div class="intro-blurb">
                        <?=w('intro')?>
                    </div>
                    <p class="intro-link">
                        <?=w('intro_link')?>
                    </p>
                </div>
            </div>
            <p class="video-play" <?=wa('video')?>>
                <? if ( w('video')->video ): ?>
                    <a href="http://www.youtube.com/watch?v=<?=w('video')->video?>"><?=w('video')->single?></a>
                <? elseif( wordlet_edit_mode() ): ?>
                    Add Video
                <? endif ?>
            </p>
        </div>
    </div>

    <script id="video-template" type="text/x-javascript-template">
        <div class="video-block">
            <iframe width="560" height="315" src="http://www.youtube.com/embed/<?=w('video')->video?>?autoplay=true" frameborder="0" allowfullscreen></iframe>
            <p class="close">
                <a href="#">Close</a>
            </p>
        </div>
    </script>
</div>

<div class="second-block">
    <div class="first-sub">
        <h2 class='headline'><?=w('second_block_first_sub_headline')?></h2>
        <div class="text-block cms">
            <?=w('second_block_first_sub_first_text')?>
        </div>
        <h3 class='subheadline'><?=w('second_block_first_sub_subheadline')?></h3>
        <div class="text-block cms">
            <?=w('second_block_first_sub_second_text')?>
        </div>
        <div class="important" <?= wa('second_block_first_sub_cta')?>>
            <a href="<?=w('second_block_first_sub_cta')->href?>"><?=w('second_block_first_sub_cta')->single(false)?></a>
        </div>
    </div>

    <div class="second-sub form_wrapper">
        <div class="default-state">
            <div class="default-content">
                <h2 class='headline'><?=w('second_block_second_sub_headline')?></h2>
                <div class="teams-wrapper" <?=wa('teams')?>>
                    <ul class="teams-menu">
                        <? foreach ( wl('teams') as $team ): ?>
                        <li class='team'>
                            <a href="<?=wu('intelchange_winners_home')?>#<?=$team->token?>"><?=$team->single(false)?></a>
                        </li>
                        <? endforeach ?>
                    </ul>
                    <div class="teams-content">
                        <? foreach ( wl('teams') as $team ): ?>
                            <?
                                $team_winner = wf($team->token.'_team', 'token', 'winner');
                                $team_mentor1 = wf($team->token.'_team', 'token', 'mentor1'); // these shouldn't be hard coded but eff it I AIN'T GOT TIME
                                $team_mentor2 = wf($team->token.'_team', 'token', 'mentor2');
                                $team_mentor3 = wf($team->token.'_team', 'token', 'mentor3');
                            ?>
                            <div id='<?=$team->token?>' class="team" <?=wa($team->token.'_team')?>>
                                <a class="winner" href='<?=wu('intelchange_winners_teams')?>?team=<?=$team->token?>&member=<?=$team_winner->token?>'>
                                    <div class="portrait">
                                        <img src="<?=$team_winner->img_src?>" alt="<?=$team_winner->single(false)?>">
                                    </div>
                                    <div class="winner-text-block">
                                        <h3 class='winner-headline'>
                                            <span class="title"><?=w($team_winner->token.'_member_title_label')?></span>
                                            <span class='name'><?=strtok($team_winner->single(false), " ")?></span>
                                        </h3>
                                        <div class='facts'><?=$team_winner->multi_short(false)?></div>
                                    </div>
                                </a>
                                <div class="mentors-wrapper">
                                    <h3 class='mentors-headline'>
                                        <?=w('second_block_second_sub_subheadline')?>
                                    </h3>
                                    <div class="mentors">
                                        <a class="mentor one" href='<?=wu('intelchange_winners_teams')?>?team=<?=$team->token?>&member=<?=$team_mentor1->token?>'>
                                            <img src="<?=$team_mentor1->thumb_src?>" alt="<?=$team_mentor1->single(false)?>">
                                            <span class='name'><?=strtok($team_mentor1->single(false), " ")?></span>
                                            <span class="company"><?=w($team->token.'_'.$team_mentor1->token.'_company')?></span>
                                            <span class="title"><?=w($team_mentor1->token.'_member_title_label')?></span>
                                        </a>
                                        <a class="mentor two" href='<?=wu('intelchange_winners_teams')?>?team=<?=$team->token?>&member=<?=$team_mentor2->token?>'>
                                            <img src="<?=$team_mentor2->thumb_src?>" alt="<?=$team_mentor2->single(false)?>">
                                            <span class='name'><?=strtok($team_mentor2->single(false), " ")?></span>
                                            <span class="company"><?=w($team->token.'_'.$team_mentor2->token.'_company')?></span>
                                            <span class="title"><?=w($team_mentor2->token.'_member_title_label')?></span>
                                        </a>
                                        <a class="mentor three" href='<?=wu('intelchange_winners_teams')?>?team=<?=$team->token?>&member=<?=$team_mentor3->token?>'>
                                            <img src="<?=$team_mentor3->thumb_src?>" alt="<?=$team_mentor3->single(false)?>">
                                            <span class='name'><?=strtok($team_mentor3->single(false), " ")?></span>
                                            <span class="company"><?=w($team->token.'_'.$team_mentor3->token.'_company')?></span>
                                            <span class="title"><?=w($team_mentor3->token.'_member_title_label')?></span>
                                        </a>
                                    </div>
                                    <div class="important">
                                        <a href="<?=wu('intelchange_winners_teams')?>?team=<?=$team->token?>"><?=w('read_more') ?></a>
                                    </div>
                                </div>
                            </div>
                        <? endforeach ?>
                    </div>
                </div>
            </div>
            <div class="stay-contected cta" <?=wa('stay_connected')?>>
                <a href="#stay-connected">
                    <? if ( $w = w('stay_connected') ): ?>
                        <h4><?=$w->single(false)?></h4>
                        <?=$w->multi(false)?>
                    <? endif ?>
                </a>
            </div>
        </div>

        <div id="stay-connected" class="form-state form-content" <?=wa('stay_connected_form')?>>
            <?=w('stay_connected_form')?>
        </div>
    </div>
</div>