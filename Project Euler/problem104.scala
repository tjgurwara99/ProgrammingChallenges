import math.BigInt

object problem104 {

    private val count = new Array[Int](300)

    def isPandigital(n0: Int): Boolean = {
        if (n0 < 100000000) return false
        val seen = new Array[Boolean](10)
        seen(0) = true
        var n = n0
        while (n > 0) {
            if (seen(n % 10)) return false
            seen(n % 10) = true
            n /= 10
        }
        true
    }

    def isDoublePandigital(s: String): Boolean = {
        if (s.length < 9) return false
        count('0') = 2
        for (i <- "123456789") count(i) = 0
        for (i <- 0 until 9) {
            if (count(s(i)) > 0) return false
            count(s(i)) = 1
        }
        true
    }

    def time(op: => Unit): Unit = {
        val prev = System.currentTimeMillis()
        op
        println(s"Time taken: ${System.currentTimeMillis() - prev}ms")
    }

    def main(args: Array[String]): Unit = time {
        var a, b: BigInt = 1
        var a1, b1: Int = 1
        var i = 1
        var found = false
        while (!found) {
            i += 1
            found = isPandigital(b1) && isDoublePandigital(b.toString)
            val c = a+b
            a = b; b = c
            val c1 = (a1+b1) % 1000000000
            a1 = b1; b1 = c1
        }
        println(i)
    }
}