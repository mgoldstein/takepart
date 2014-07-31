<?php namespace Participant\MetaData\Video;

interface SharedVideo
{
  public function openGraphURL($https = FALSE);

  public function url($https = FALSE);

  public function width();

  public function height();
}
