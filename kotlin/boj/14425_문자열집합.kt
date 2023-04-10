import java.io.*
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val (n, m) = readLine().let { it.split(" ")[0].toInt() to it.split(" ")[1].toInt() }
    val nstr = (0 until n).map { readLine() }
    val mstr = (0 until m).map { readLine() }

    println(mstr.filter { nstr.contains(it) }.size)
}

