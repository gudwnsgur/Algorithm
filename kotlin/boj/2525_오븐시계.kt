import java.io.*
import java.util.*
 
fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val token = StringTokenizer(readLine())
    val (A, B) = Integer.parseInt(token.nextToken()) to Integer.parseInt(token.nextToken())
    val C = Integer.parseInt(readLine())

    println("${(A + (B + C) / 60) % 24} ${(B + C) % 60}")
}

