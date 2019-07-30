object problem351 {
  /* From some analysis we have H(n) = 6 * SUM(k - totient(k)) 1 <= k <= n
   * Combine the sieve and the sum into one. */
  def h(n: Int): Long = {
    val totient = new Array[Int](n+1)
    val isComposite = new Array[Boolean](n+1)

    for (i <- 1 to n) totient(i) = i
    for (i <- 2 to n) {
      if (!isComposite(i)) {
        var j = i
        while (j <= n) {
          totient(j) = totient(j)/i*(i-1)
          isComposite(j) = true
          j += i
        }
      }
    }
    var total: Long = 0
    for (i <- 1 to n) total += i - totient(i)
    6 * total
  }

  def main(args: Array[String]): Unit = {
    val before = System.currentTimeMillis()
    println(h(100000000))
    println("Time taken: " + (System.currentTimeMillis() - before) + "ms")
  }
}
