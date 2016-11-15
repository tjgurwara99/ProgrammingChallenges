object problem66 {

  def isPerfectSquare(n: Int): Boolean = {
    val squareRoot: Int = Math.sqrt(n.toDouble).toInt
    squareRoot*squareRoot == n
  }

  case class ContinuedFraction(num: (BigInt, BigInt), den: (BigInt, BigInt) ) {
    def reciprocal: ContinuedFraction = ContinuedFraction(den, num)

    def rationaliseDenominator: ContinuedFraction = {
      val d: BigInt = den._1 - (den._2 * den._2)
      ContinuedFraction((den._1, -den._2), (1, d / num._2))
    }
  }

  def getContinuedFraction(n: Int): List[Int] = {

    val floorRoot = Math.sqrt(n.toDouble).toInt
    val firstFract = ContinuedFraction((BigInt(n), BigInt(-floorRoot)), (1, 1))

    def fractionHelper(currentFract: ContinuedFraction, acc: List[Int], isFirst: Boolean): List[Int] = {
      if (isFirst || currentFract != firstFract) {

        val tempFrac = currentFract.reciprocal.rationaliseDenominator
        val topInt = tempFrac.num._2 + floorRoot
        val botInt = tempFrac.den._2

        fractionHelper(
          ContinuedFraction((tempFrac.num._1, (topInt % botInt) - floorRoot), tempFrac.den),
          acc ::: List((topInt / botInt).intValue), false)

      } else acc
    }

    fractionHelper(firstFract, List(floorRoot), true)
  }

  def getMinX(d: Int): (BigInt, BigInt) = {
    val fracRep = getContinuedFraction(d)

    def getNextConvergent(n1: BigInt, d1: BigInt, n2: BigInt, d2: BigInt, xs: List[Int]): (BigInt, BigInt) = xs match {
      case Nil => getNextConvergent(n1, d1, n2, d2, fracRep.tail)
      case y :: ys => {
        val newN = y * n2 + n1
        val newD = y * d2 + d1
        if (newN*newN - d*newD*newD == 1) (newN, newD)
        else getNextConvergent(n2, d2, newN, newD, ys)
      }
    }

    getNextConvergent(1, 0, fracRep.head, 1, fracRep.tail)
  }

  def main(args: Array[String]): Unit = {
    val before: Long = System.currentTimeMillis()
    println((0 to 1000).zipWithIndex.filterNot(v => isPerfectSquare(v._1)).map(v => (getMinX(v._1), v._2)).maxBy(v => v._1._1))
    println("Time taken: " + (System.currentTimeMillis() - before) + "ms")
  }

}
