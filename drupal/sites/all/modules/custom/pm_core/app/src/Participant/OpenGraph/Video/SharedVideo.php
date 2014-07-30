<?php namespace Participant\OpenGraph\Video;

interface SharedVideo
{
  public function url($https = FALSE);

  public function width();

  public function height();
}
