<?php namespace Participant\Entities\Video;

/**
 * @Entity(repositoryClass="Participant\Entities\Video\NodeImportRepository")
 * @Table(name="pm_jwplatform_imports")
 */
class NodeImport {

  /**
   * @Id
   * @Column(type="integer")
   * @GeneratedValue
   */
  private $id;

  /**
   * @Column(type="string")
   */
  private $video_key;

  /**
   * @Column(type="integer", name="created")
   */
  private $created_at;

  /**
   * @Column(type="integer", name="imported")
   */
  private $imported_at;

  public function getId() {
    return $this->id;
  }

  public function getVideoKey() {
    return $this->video_key;
  }

  public function setVideoKey($video_key) {
    $this->video_key = $video_key;
  }

  public function getCreatedAt() {
    return $this->created_at;
  }

  public function setCreatedAt($created_at) {
    $this->created_at = $created_at;
  }

  public function getImportedAt() {
    return $this->imported_at;
  }

  public function setImportedAt($imported_at) {
    $this->imported_at = $imported_at;
  }
}
