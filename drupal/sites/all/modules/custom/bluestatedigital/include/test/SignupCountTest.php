<?php

include_once dirname(__FILE__) . '/../bsdapi/bsd.api.inc';

class SignupCountTest extends PHPUnit_Framework_TestCase {
/*
  const API_ID = "takepart-com";
  const API_SECRET = "ae2cbc9a230ba4c36a9972fb7eeef41e2f2c62f8";
  const REST_METHOD = BlueStateDigitalApi::REST_METHOD_CURL;
  const REQUEST_BASE = "http://action.takepart.com/page/api/";
*/
  const API_ID = "takepart-qa";
  const API_SECRET = "4a5ecec2568a4ab7a74e26032b8f886c9f8d3057";
  const REST_METHOD = BlueStateDigitalApi::REST_METHOD_CURL;
  const REQUEST_BASE = "http://tkprtdemo.bsdtoolsdemo.com/page/api/";

  public function testConstruction() {
    $api = new BlueStateDigitalSignupApi(self::API_ID, self::API_SECRET,
      self::REST_METHOD, self::REQUEST_BASE);
    return $api;
  }

  /**
   * @depends testConstruction
   */
  public function testSignupCountUtil($api) {
    $count = $api->signupCountUtil(8);
    $this->assertEquals(341, $count);
    return $api;
  }
}
