import scala.math._

object problem100 {
  def main(args: Array[String]): Unit = {
    var n: BigInt = 21
    var b: BigInt = 15

    val target: BigInt = BigInt(10).pow(12)

    while (n < target) {
      val newN: BigInt = (4*b)+(3*n)-3
      val newB: BigInt = (3*b)+(2*n)-2
      n = newN
      b = newB
    }

    println(n)
    println(b)
  }
}
