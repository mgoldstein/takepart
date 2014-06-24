<?php namespace Participant\Entities\Video;

use Doctrine\ORM\EntityRepository;

class NodeImportRepository extends EntityRepository
{
  public function getExistingImports($keys) {
    $builder = $this->_em->createQueryBuilder();
    $query = $builder->select('ni')
      ->from('Participant\Entities\Video\NodeImport', 'ni')
      ->where($builder->expr()->in('ni.video_key', $keys))
      ->getQuery();
    return $query->getResult();
  }

  public function getPendingImports() {
    $builder = $this->_em->createQueryBuilder();
    $query = $builder->select('ni')
      ->from('Participant\Entities\Video\NodeImport', 'ni')
      ->where($builder->expr()->isNull('ni.imported_at'))
      ->getQuery();
    return $query->getResult();
  }
}
