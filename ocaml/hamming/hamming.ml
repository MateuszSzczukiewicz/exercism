type nucleotide = A | C | G | T

let hamming_distance (first_list : nucleotide list) (second_list : nucleotide list) =
    let rec compare first_list second_list =
        match first_list, second_list with
        | [], [] -> Ok 0
        | f :: fs, s :: ss ->
            let diff = if f <> s then 1 else 0 in
            (match compare fs ss with
                | Ok count -> Ok (diff + count)
                | Error msg -> Error msg)

        | _ -> Error "left and right strands must be of equal length"
    in
    match first_list, second_list with
    | [], [] -> Ok 0
    | [], _ -> Error "left strand must not be empty"
    | _, [] -> Error "right strand must not be empty"
    | _ -> compare first_list second_list

