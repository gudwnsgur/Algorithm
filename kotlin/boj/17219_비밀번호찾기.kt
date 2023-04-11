fun main() = with(System.`in`.bufferedReader()) {
    val map = mutableMapOf<String, String>()
    val (n, m) = readLine().trim().split(" ").let { it[0].toInt() to it[1].toInt() }

    for(i in 1..n) {
        readLine().trim().split(" ").let {
            map[it[0]] = it[1]
        }
    }
    for(i in 1..m) {
        println(map[readLine().trim()])
    }
}

