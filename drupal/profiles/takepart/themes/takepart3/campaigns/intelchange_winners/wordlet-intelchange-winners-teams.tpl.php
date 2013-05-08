<?
    $cur_team = $_GET['team'];
    $cur_member = $_GET['member'];
?>
<div class="first-block">
    <div class="team-menu">
    <?
   $teams = wl('teams');
    ?>
    <? foreach ( $teams as $i => $team ): ?>
        <?
        $active_team = $cur_team == $team->token;
        ?>
        <div class="team<?=($active_team?' active':'')?>">
            <? $team_members = wl($team->token.'_team'); ?>
            <span class="team-name"><?=$team->single(false)?></span>
            <? foreach ( $team_members as $i => $team_member ): ?>
                <?
                $active_member = $cur_member == $team_member->token;
                ?>
                <a href="<?=wu('intelchange_winners_teams')?>?team=<?=$team->token?>&member=<?=$team_member->token?>" class="member<?=($active_member?' active':'')?>">
                    <span class="name"><?=$team_member->single(false)?></span>
                    <span class="company"><?=wl($team_member->token.'_'.$team_member->token.'_company')?></span>
                    <span class="title"><?=wl($team_member->token.'_member_title_label')?></span>
                </a>
            <? endforeach ?>
        </div>
    <? endforeach ?>
    </div>
</div>
<div class="second-block">
    <div class="member">
        <?
        $team = wordlet_find('team', 'token', $cur_team);
        $team_member = wordlet_find($team->token.'_team', 'token', $cur_member);
        ?>
        <img src="<?=$team_member->img_src?>" alt="<?=$team_member->single(false)?>">
        <h2 class='title'><span class='member-title'><?=wl($team_member->token.'_member_title_label')?></span> <?=$team_member->single(false)?></h2>
        <div class='facts'><?=$team_member->multi_short(false)?></div>
        <div class='blurb'><?=$team_member->multi(false)?></div>
        <div class="video">
            <iframe class="video-player" width="541" height="305" src="http://www.youtube.com/embed/<?=$team_member->video?>" frameborder="0" allowfullscreen></iframe>
        </div>
    </div>
</div>
