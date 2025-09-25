type nucleotide = A | C | G | T

let rec hamming_distance (first_list : nucleotide list) (second_list : nucleotide list) =
        match first_list, second_list with
        | [], [] -> Ok 0
        | [], _ | _, [] -> Error "strands must be of equal length"
        | f :: fs, s :: ss ->
            let diff = if f <> s then 1 else 0 in
            Result.map (fun count -> diff + count) (hamming_distance fs ss)
