/* Correct answer in 180ms */
object problem80 {

  val scaleFactor = BigInt(10).pow(200)

  def preciseSqrt(n: Int): BigInt = {
    val nBig = BigInt(n) * scaleFactor
    def sqrtHelper(acc: BigInt, err: BigInt): BigInt = {
      if (err == 0) acc
      else {
        val newAcc = (nBig / acc + acc) / 2
        sqrtHelper(newAcc, (newAcc - acc).abs)
      }
    }

    sqrtHelper(nBig/2, 1)
  }

  def count(n: Int): Int = preciseSqrt(n).toString.take(100).map(c => c - '0').sum

  def isIrrational(n: Int): Boolean = !Math.sqrt(n).isValidInt

  def main(args: Array[String]): Unit = {
    val before = System.currentTimeMillis
    println((1 to 100).filter(isIrrational).map(count).sum)
    println("Time taken: " + (System.currentTimeMillis - before) + "ms")
  }

}
